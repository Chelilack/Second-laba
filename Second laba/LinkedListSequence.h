#pragma once
#include "Sequence.h"
#include "LinkedList.h"
template <class T>
class LinkedListSequence : Sequence<T>
{
private:
    LinkedList<T>* items;
    int lenght;
public:
    LinkedListSequence(T* items, int count): lenght(count) { this->items=new LinkedList<T>(items, count); }
    LinkedListSequence():lenght(0) { this->items = new LinkedList<T>(); }
    LinkedListSequence(const LinkedList <T>* list):lenght(list->GetLength()) { this->items = new LinkedList<T>(list); }
    ~LinkedListSequence() { delete this->items; }
public:
    virtual T GetFirst()                          const override { return this->items->GetFirst(); }
    virtual T GetLast()                           const override { return this->items->GetLast(); }
    virtual T Get (int index)                     const override { return this->items->Get(index); }
    virtual int  GetLength()                            override { return this->lenght; }
    virtual void Remove   (int index)                   override { this->lenght--; this->items->Remove(index); }
    virtual void Append   (T item)                      override { this->lenght++; this->items->Append(item); }
    virtual void Prepend  (T item)                      override { this->lenght++; this->items->Prepend(item); }
    virtual void InsertAt(int index, T item)            override { this->lenght++; this->items->InsertAt(index,item); }
    virtual Sequence<T>* Concat(Sequence<T>* list)const override
    { 
        list = (LinkedListSequence*)list;
        LinkedListSequence<T>* subSequence = new LinkedListSequence(this->items);
        for (int i = 0; i < list->GetLength(); i++)
        {
            subSequence->Append(list->Get(i));
        }
        return (Sequence<T>*)subSequence;
    }
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) const override 
    {
        Sequence<T>* subSequence = new LinkedListSequence();

        for (int i = startIndex; i < endIndex; i++)
        {
            subSequence->Append(this->Get(i));
        }
        return subSequence;
    }
};


