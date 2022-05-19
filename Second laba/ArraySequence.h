#pragma once
#include "Sequence.h"
#include "DynamicArray.h"
template <class T> 
class ArraySequence : Sequence<T>
{
private:
    DynamicArray<T>* items;
    int count;
public:
    ArraySequence(T* items, int count):count(count) { this->items = new DynamicArray<T>(items, count); }
    ArraySequence() :count(0) { this->items = new DynamicArray<T>(0); }
    ArraySequence(const DynamicArray<T>* dynamicArray) :count(dynamicArray->GetCount())  { this->items = new DynamicArray<T>(*dynamicArray); }
    ~ArraySequence() { delete this->items; }
public:
    virtual T GetFirst()                           const override { return this->items->Get(0); }
    virtual T GetLast()                            const override { return this->items->Get(this->items->GetCount() - 1); }
    virtual T Get(int index)                       const override { return this->items->Get(index); }
    virtual int GetLength()                              override { return this->items->GetCount(); }
    virtual void Remove(int index)                       override { this->count--; this->items->Remove(index);  }
    virtual void Append(T item)                          override { this->count++; this->items->Set(this->items->GetCount(), item);  }
    virtual void Prepend(T item)                         override { this->count++; this->items->Set(0, item); }
    virtual void InsertAt(int index, T item)             override { this->count++; this->items->Set(index, item);}
    virtual Sequence<T>* Concat(Sequence<T>* list) const override
    {
        list = (ArraySequence*)list;
        ArraySequence<T>* result = new ArraySequence(this->items);
        for (int i = 0; i < list->GetLength(); i++) 
        {
            result->Append(list->Get(i));
        }
        return result;
    }
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) const override
    {
        Sequence<T>* subSequence = new ArraySequence();
        for (int i = startIndex; i < endIndex ; i++) 
        {
            subSequence->Append(this->Get(i));
        }
        return subSequence;
    }
};

