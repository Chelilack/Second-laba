#pragma once
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
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
	void SetBegin(Item<T>* BeginPointer); 
	void SetEnd(Item<T>* EndPointer);
	void SetLength(T count);

	Item<T>* GetBegin() const; 
	Item<T>* GetEnd() const; 
	int GetLength() const; 
	
	
	LinkedList();
	LinkedList(T* items, int count);
	
	LinkedList(const LinkedList <T>* list);
	
public:
	Item<T>* FindWithIndex(int index);
	
	T Get(int index);
	T GetFirst();
	T GetLast();
	void InsertAt(T item, int index);
	void Append(T item);
	void Prepend(T item);
	LinkedList<T>* GetSubList(int startIndex, int endIndex);
	LinkedList<T>* Concat(LinkedList<T>* list);
	void Remove(int index);
	void Print();
	

};

template<typename T>
void LinkedList<T>::SetBegin(Item<T>* BeginPointer) 
{
	this->begin = BeginPointer; 
}
template<typename T>
void LinkedList<T>::SetEnd(Item<T>* EndPointer) 
{
	this->end = EndPointer; 
}
template<typename T>
void LinkedList<T>::SetLength(T count) 
{
	this->length = count; 
}
template<typename T>
Item<T>* LinkedList<T>::GetBegin() const 
{
	return this->begin; 
}
template<typename T>
Item<T>* LinkedList<T>::GetEnd() const 
{
	return this->end; 
}

template<typename T>
int LinkedList<T>::GetLength() const 
{
	return this->length; 
}

template<typename T>
LinkedList<T>::LinkedList() :begin(NULL), end(NULL), length(0) {}

template<typename T>
LinkedList<T>::LinkedList(T* items, int count) : length(count)
{
	Item<T>* ItemPreviosPointer = new Item<T>(items[0]);
	SetBegin(ItemPreviosPointer);
	for (int i = 1; i < length; i++)
	{
		Item<T>* ItemPointer = new Item<T>(items[i]);
		ItemPointer->SetPrev(ItemPreviosPointer);
		ItemPreviosPointer->SetNext(ItemPointer);
		ItemPreviosPointer = ItemPointer;
	}
	SetEnd(ItemPreviosPointer);
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList <T>* list) 
{
	this->SetLength(list->GetLength());
	Item<T>* SourceItemPointer = list->GetBegin();
	Item<T>* CopyItemPointer = new Item<T>(SourceItemPointer->GetValue());
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

template<typename T>
Item<T>* LinkedList<T>::FindWithIndex(int index)
{
	int counter;
	Item<T>* temporaryPointer;
	if (index == -1) { return NULL; }
	if (index <= this->GetLength() / 2)
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
		counter = this->GetLength() - 1;
		temporaryPointer = this->GetEnd();
		while (counter != index)
		{
			temporaryPointer = temporaryPointer->GetPrev();
			counter--;
		}
	}
	return temporaryPointer;
}

template<typename T>
T LinkedList<T>::Get(int index)
{
	return this->FindWithIndex(index)->GetValue();
}

template<typename T>
T LinkedList<T>::GetFirst()
{
	return this->Get(0);
}

template<typename T>
T LinkedList<T>::GetLast()
{
	return this->Get(this->GetLength() - 1);
}

template<typename T>
void LinkedList<T>::InsertAt(T item, int index)
{
	Item<T>* oldItem = NULL;
	Item<T>* pasteItem = new Item<T>(item);
	if (index == 0 && this->FindWithIndex(index) == NULL)
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

template<typename T>
void LinkedList<T>::Append(T item)
{
	Item<T>* oldItem = NULL;
	Item<T>* pasteItem = new Item<T>(item);
	if (this->FindWithIndex(this->GetLength() - 1) == NULL)
	{
		this->SetBegin(pasteItem);
		this->SetEnd(pasteItem);
	}
	else
	{
		oldItem = this->FindWithIndex(this->GetLength() - 1);
		pasteItem->SetPrev(oldItem);
		oldItem->SetNext(pasteItem);
		this->SetEnd(pasteItem);
	}
	this->SetLength(this->GetLength() + 1);
}

template<typename T>
void LinkedList<T>::Prepend(T item)
{
	this->InsertAt(item, 0);
}

template<typename T>
void LinkedList<T>::Remove(int index)
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

template<typename T>
void LinkedList<T>::Print()
{
	Item<T>* example = this->GetBegin();
	for (int i = 0; i < this->GetLength(); i++)
	{
		cout << example->GetValue();
		example = example->GetNext();
	}
	cout << endl;
}
template<typename T>
LinkedList<T>* LinkedList<T>::GetSubList(int startIndex, int endIndex)
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

template<typename T>
LinkedList<T>* LinkedList<T>::Concat(LinkedList<T>* list)
{
	LinkedList<T>* newList = new LinkedList<T>(this);
	newList->SetLength(newList->GetLength() + list->GetLength());
	newList->GetEnd()->SetNext(list->GetBegin());
	list->GetBegin()->SetPrev(newList->GetEnd());
	newList->SetEnd(list->GetEnd());
	return newList;
}
