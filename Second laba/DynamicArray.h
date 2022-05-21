#pragma once
using namespace std;

template<typename T>
class DynamicArray
{
private:
	T* arrayPointer;
	int size;
	int count;

public:
	DynamicArray(int size);
	DynamicArray(T* items, int count);
	DynamicArray(const DynamicArray<T>* dynamicArray);
	~DynamicArray();
public:
	int GetSize()const ;
	int GetCount() const ;
	T Get(int index) const ;
	void Set(int index, T value);
	void Resize(int newSize);
	void Remove(int index);
};

template<typename T>
DynamicArray<T>::DynamicArray(int size) : count(0)
{
	this->arrayPointer = new T[size];
	this->size = size;
}

template<typename T>
DynamicArray<T> ::DynamicArray(T* items, int count) : size(count * 2), count(count)
{
	this->arrayPointer = new T[this->size];
	for (int i = 0; i < count; i++)
	{
		this->arrayPointer[i] = items[i];
	}
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>* dynamicArray) 
{
	this->arrayPointer = new T[dynamicArray->GetSize()];
	this->count = dynamicArray->GetCount();
	this->size = dynamicArray->GetSize();
	for (int i = 0; i < dynamicArray->GetCount(); i++)
	{
		this->Set(i, dynamicArray->Get(i));
	}
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
	delete[] this->arrayPointer;
}

template<typename T>
int DynamicArray<T>::GetSize() const 
{
	return this->size; 
}

template<typename T>
int DynamicArray<T>::GetCount() const 
{
	return this->count; 
}

template<typename T>
T DynamicArray<T>::Get(int index) const
{
	return this->arrayPointer[index];
}

template<typename T>
void DynamicArray<T>::Set(int index, T value)
{
	if (this->size == this->count)
	{
		this->size += 1;
		Resize(GetSize());
		this->count -= 1;
	}
	this->count += 1;
	memmove(this->arrayPointer + index + 1, this->arrayPointer + index, (this->count - index - 1) * sizeof(T));
	this->arrayPointer[index] = value;

}
 
template<typename T>
void DynamicArray<T>::Resize(int newSize)
{
	T* newSizePointer = new T[newSize];
	int copySize = newSize > (this->size) ? this->size : newSize;
	memcpy(newSizePointer, this->arrayPointer, copySize * sizeof(T));
	this->count = copySize;
	this->size = newSize;
	delete[] this->arrayPointer;
	this->arrayPointer = newSizePointer;
}
 
template<typename T>
void DynamicArray<T>::Remove(int index)
{
	this->count -= 1;
	memmove(this->arrayPointer + index, this->arrayPointer + (index + 1), (this->count - index) * sizeof(T));
}
 