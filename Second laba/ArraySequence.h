#pragma once
#include "Sequence.h"
#include "DynamicArray.h"
template <class T> 
class ArraySequence : public Sequence<T>
{
private:
    DynamicArray<T>* items;
    int count;
public:
    ArraySequence(T* items, int count);
    ArraySequence();
    ArraySequence(const DynamicArray<T>* dynamicArray);
    ~ArraySequence();
public:
    virtual T GetFirst()const override;
    virtual T GetLast()const override;
    virtual T Get(int index)const override;
    virtual int GetLength()override;
    virtual void Remove(int index)override;
    virtual void Append(T item)override; 
    virtual void Prepend(T item)override; 
    virtual void InsertAt(T item, int index)override; 
    virtual Sequence<T>* Concat(Sequence<T>* list) const override;
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) const override;
};

template <class T>
ArraySequence<T>::ArraySequence(T* items, int count) :count(count)
{
    this->items = new DynamicArray<T>(items, count);
}

template <class T>
ArraySequence<T>::ArraySequence() : count(0) 
{
    this->items = new DynamicArray<T>(0); 
}

template <class T>
ArraySequence<T>::ArraySequence(const DynamicArray<T>* dynamicArray) :count(dynamicArray->GetCount()) 
{ 
    this->items = new DynamicArray<T>(*dynamicArray); 
}

template <class T>
ArraySequence<T> :: ~ArraySequence() 
{
    delete this->items; 
}

template <class T>
T ArraySequence<T>::GetFirst() const
{ 
     return this->items->Get(0); 
}

template <class T>
T ArraySequence<T>::GetLast()const 
{ 
    return this->items->Get(this->items->GetCount() - 1); 
}

template <class T>
T ArraySequence<T>::Get(int index) const 
{
    return this->items->Get(index);
}

template <class T>
int ArraySequence<T> ::GetLength() 
{
    return this->items->GetCount();
}

template <class T>
void ArraySequence<T>::Remove(int index) 
{ 
    this->count--;
    this->items->Remove(index);
}

template <class T>
void ArraySequence<T>::Append(T item) 
{ 
    this->count++;
    this->items->Set(this->items->GetCount(), item); 
}

template <class T>
void ArraySequence<T>::Prepend(T item) 
{ 
    this->count++;
    this->items->Set(0, item); 
}

template <class T>
void ArraySequence<T>::InsertAt(T item, int index) 
{ 
    this->count++;
    this->items->Set(index, item); 
}

template <class T>
Sequence<T>* ArraySequence<T>::Concat(Sequence<T>* list) const 
{
    list = (ArraySequence*)list;
    ArraySequence<T>* result = new ArraySequence(this->items);
    for (int i = 0; i < list->GetLength(); i++)
    {
        result->Append(list->Get(i));
    }
    return result;
}

template <class T>
Sequence<T>* ArraySequence<T>::GetSubsequence(int startIndex, int endIndex) const 
{
    Sequence<T>* subSequence = new ArraySequence();
    for (int i = startIndex; i < endIndex + 1; i++)
    {
        subSequence->Append(this->Get(i));
    }
    return subSequence;
}