#pragma once
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

template<typename T>
class Item
{
private:
	Item<T>* next;
	Item<T>* prev;
	T value;
public:
	Item() : next(NULL), prev(NULL), value(NULL) {}
	Item(T example) : next(NULL), prev(NULL), value(example) {}
	
	Item<T>* GetNext() { return this->next; }
	Item<T>* GetPrev() { return this->prev; }
	T GetValue()       { return this->value; }

    void SetNext(Item<T>* NextPointer) {  this->next  = NextPointer; }
    void SetPrev(Item<T>* PrevPointer) {  this->prev  = PrevPointer; }
	void SetValue(T example)           {  this->value = example;    }

};

template<typename T>
class LinkedList 
{
private:
	Item<T>* begin;
	Item<T>* end;
	int length;
public:
	void SetBegin(Item<T>* BeginPointer) { this->begin = BeginPointer; }
	void SetEnd(Item<T>* EndPointer)     { this->end = EndPointer;     }
	void SetLength(T count)              { this->length = count;       }

	Item<T>* GetBegin() const { return this->begin;  }
	Item<T>* GetEnd() const  { return this->end;    }
	int GetLength() const    { return this->length; }
	
	
	LinkedList() :begin(NULL), end(NULL), length(0) {}
	LinkedList(T* items, int count) : length(count) 
	{
		Item<T>* ItemPreviosPointer = new Item<T>(items[0]);
		SetBegin(ItemPreviosPointer);
		for (int i=1; i < length; i++) 
		{
			Item<T>* ItemPointer = new Item<T>(items[i]);
			ItemPointer->SetPrev(ItemPreviosPointer);
			ItemPreviosPointer->SetNext(ItemPointer);
			ItemPreviosPointer = ItemPointer;
		}
		SetEnd(ItemPreviosPointer);
	}
	
	LinkedList(const LinkedList <T>* list) 
	{
		this->SetLength(list->GetLength());
		Item<T>* SourceItemPointer = list->GetBegin();
		Item<T>* CopyItemPointer = new Item<T> (SourceItemPointer->GetValue());
		this->SetBegin(CopyItemPointer);
		while (SourceItemPointer != list->GetEnd())
		{
			Item<T>* PreviousCopyItemPointer = CopyItemPointer;
			SourceItemPointer = SourceItemPointer->GetNext();
			CopyItemPointer = new Item<T>(SourceItemPointer->GetValue());
			CopyItemPointer->SetPrev(PreviousCopyItemPointer);
			PreviousCopyItemPointer->SetNext(CopyItemPointer);
		}
		this->SetEnd(CopyItemPointer);
	}
	Item<T>* FindWithIndex(int index)
	{
		int counter;
		Item<T>* temporaryPointer;
		if (index == -1) { return NULL; }
		if (index <= this->GetLength() / 2 )
		{
			counter = 0;
			temporaryPointer = this->GetBegin();
			while (counter != index)
			{
				temporaryPointer = temporaryPointer->GetNext();
				counter++;
			}
		}
		else
		{
			counter = this->GetLength()-1;
			temporaryPointer = this->GetEnd();
			while (counter != index)
			{
				temporaryPointer = temporaryPointer->GetPrev();
				counter--;
			}
		}
		return temporaryPointer;
	}
	T Get(int index) 
	{
		return this->FindWithIndex(index)->GetValue();
	}
	T GetFirst() 
	{
		return this->Get(0);
	}
	T GetLast() 
	{
		return this->Get(this->GetLength()-1);
	}
	void InsertAt(T item, int index)
	{
		Item<T>* oldItem =NULL;
		Item<T>* pasteItem = new Item<T>(item);
		if (index == 0 && this->FindWithIndex(index)==NULL)
		{
			this->SetBegin(pasteItem);
			this->SetEnd(pasteItem);
		}
		else if (index == 0)
		{
			oldItem = this->FindWithIndex(index);
			oldItem->SetPrev(pasteItem);
			pasteItem->SetNext(oldItem);
			this->SetBegin(pasteItem);
		}
		else if (index == this->GetLength())
		{
			oldItem = this->FindWithIndex(index-1);
			pasteItem->SetPrev(oldItem);
			oldItem->SetNext(pasteItem);
			this->SetEnd(pasteItem);
		}
		else 
		{
			oldItem = this->FindWithIndex(index);
			pasteItem->SetPrev(oldItem->GetPrev());
			oldItem->SetPrev(pasteItem);
			pasteItem->SetNext(oldItem);
			pasteItem->GetPrev()->SetNext(pasteItem);
		}
		this->SetLength(this->GetLength() + 1);
	}
	void Append(T item)
	{
		this->InsertAt(item, this->GetLength());
	}
	void Prepend(T item)
	{
		this->InsertAt(item, 0);
	}
	LinkedList<T>* GetSubList(int startIndex, int endIndex)
	{
		LinkedList<T>* subList = new LinkedList<T>();
		subList->SetLength(endIndex - startIndex + 1);
		Item<T>* SourceItemPointer = this->FindWithIndex(startIndex);
		Item<T>* CopyItemPointer = new Item<T>(SourceItemPointer->GetValue());
		subList->SetBegin(CopyItemPointer);
		while (SourceItemPointer != FindWithIndex(endIndex))
		{
			Item<T>* PreviousCopyItemPointer = CopyItemPointer;
			SourceItemPointer = SourceItemPointer->GetNext();
			CopyItemPointer = new Item<T>(SourceItemPointer->GetValue());
			CopyItemPointer->SetPrev(PreviousCopyItemPointer);
			PreviousCopyItemPointer->SetNext(CopyItemPointer);
		}
		subList->SetEnd(CopyItemPointer);
		return subList;
	}
	LinkedList<T>* Concat(LinkedList<T>* list) 
	{
		LinkedList<T>* newList = new LinkedList<T>(list);
		newList->SetLength(newList->GetLength() + list->GetLength());
		newList->GetEnd()->SetNext(list->GetBegin());
		list->GetBegin()->SetPrev(newList->GetEnd());
		newList->SetEnd(list->GetEnd());
		return newList;
	}
	void Remove(int index) 
	{
		Item<T>* uselessItemPoiner = this->FindWithIndex(index);
		if (index == 0) 
		{
			uselessItemPoiner->GetNext()->SetPrev(NULL);
			this->SetBegin(uselessItemPoiner->GetNext());
		}
		else if (index == this->GetLength() - 1) 
		{
			uselessItemPoiner->GetPrev()->SetNext(NULL);
			this->SetEnd(uselessItemPoiner->GetPrev());
		}
		else 
		{
			uselessItemPoiner->GetNext()->SetPrev(uselessItemPoiner->GetPrev());
			uselessItemPoiner->GetPrev()->SetNext(uselessItemPoiner->GetNext());
		}
		delete uselessItemPoiner;
		this->SetLength(this->GetLength() - 1);;

	}
	void Print() 
	{
		Item<T>* example = this->GetBegin();
		for (int i = 0; i < this->GetLength(); i++) 
		{
			cout << example->GetValue();
			example = example->GetNext();
		}
		cout << endl;
	}



};


