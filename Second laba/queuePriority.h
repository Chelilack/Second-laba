#pragma once
#include "LinkedListSequence.h"
#include "ArraySequence.h"
#include "Sequence.h"
#include "Errors.h"
#include "Teacher.h"
#include "Student.h"
#include "ComplexNumber.h"
#include <ostream>
using namespace std;
enum QueueType
{
	dynamicArray=1,
	linkedList=2
};
template<typename T>
class queuePriority
{
private: 
	Sequence<T>* buffer;
	int decision;
public:
	queuePriority(int decision);
	queuePriority(int decision, T* items, int count);
	~queuePriority();
public:
	void Print();
	int GetDecision();
	int GetLength();
	T Get(int index);
	void Add(T item);
	void Remove(int index);
	bool FindSubSequence(queuePriority<T>* exemplar);
	queuePriority<T>* SplitIntoTwo(queuePriority<T>* source, bool function(T,T),T n);
	queuePriority<T>* GetSubsequence(int startIndex, int endInex);
	queuePriority<T>* Concatenate(queuePriority<T>* source);

};
template<typename T>
queuePriority<T>::queuePriority(int decision) : decision(decision)
{
	if (decision != dynamicArray && decision != linkedList) 
	{
		errors(WrongDecision,"queuePriority");
		throw;
	}
	if (decision == dynamicArray) 
	{
		this->buffer = new ArraySequence<T>;
	}
	else if (decision == linkedList) 
	{
		this->buffer = new LinkedListSequence<T>;
	}
}
template<typename T>
T* shakerSort(T* items, int count) 
{
	int tr = 1;
	int min_ind = 0;
	int max_ind = count - 1;
	T pass;
	while (tr == 1)
	{
		tr = 0;
		for (int i = min_ind; i < max_ind; i++)
		{
			if (items[i]<items[i + 1])
			{
				pass = items[i];
				items[i] = items[i + 1];
				items[i + 1] = pass;
				tr = 1;
			}
		}
		max_ind -= 1;
		for (int i = max_ind; i > min_ind; i--)
		{
			if (items[i - 1]<items[i])
			{
				pass = items[i - 1];
				items[i - 1] = items[i];
				items[i] = pass;
				tr = 1;
			}
		}
		min_ind += 1;
	}
	return items;
}
template<typename T>
queuePriority<T>::queuePriority(int decision, T* items, int count) :decision(decision)
{
	items = shakerSort(items, count);
	if (decision != dynamicArray && decision != linkedList)
	{
		errors(WrongDecision, "queuePriority");
		throw;
	}
	if (decision == dynamicArray)
	{
		this->buffer = new ArraySequence<T>(items,count);
	}
	else if (decision == linkedList)
	{
		this->buffer = new LinkedListSequence<T>(items,count);
	}
}
template<typename T>
queuePriority<T>::~queuePriority() 
{

	if (this->decision != dynamicArray && this->decision != linkedList)
	{
		errors(WrongDecision, "queuePriority");
		throw;
	}
	if (decision == dynamicArray)
	{
		delete this->buffer;
	}
	else if (decision == linkedList)
	{
		delete this->buffer;
	}

}
template<typename T>
void queuePriority<T>::Print() 
{
	if (typeid(T).name() == typeid(int).name() || typeid(T).name() == typeid(float).name() || typeid(T).name() == typeid(char*).name())
	{
		for (int i = 0; i < this->buffer->GetLength(); i++)
			cout << this->Get(i) << ' ';
	}
	else if (typeid(T).name() == typeid(Teacher).name() || typeid(T).name() == typeid(ComplexNumber).name() || typeid(T).name() == typeid(Student).name()) 
	{
		for (int i = 0; i < this->buffer->GetLength(); i++)
			cout << this->Get(i)<<'\n';
	}
}
template<typename T>
void queuePriority<T>::Add(T item) 
{
	int count = 0;
	bool pasted = false;
	if(this->buffer->GetLength() == 0) this->buffer->InsertAt(item, count); 
	else {
		if (item >= this->buffer->GetFirst()) { this->buffer->Prepend(item); }
		else
		{
			while (count != this->buffer->GetLength() - 1 && pasted == false)
			{
				if ((item <= this->buffer->Get(count) && item > this->buffer->Get(count + 1))) {this->buffer->InsertAt(item, count + 1); pasted = true;}
				count++;
			}
			if (pasted == false)
			{
				if (count == this->buffer->GetLength() - 1 && item > this->buffer->Get(count))
				{
					this->buffer->InsertAt(item, count);
				}
				else
				{
					this->buffer->Append(item);
				}
			}
		}
	}
}
template<typename T>
T queuePriority<T>::Get(int index) 
{
	return this->buffer->Get(index);
}
template<typename T>
queuePriority<T>* queuePriority<T>::GetSubsequence(int startIndex, int endIndex)
{
	queuePriority* subSequence = new queuePriority<T>(this->decision);
	for (int i = startIndex; i <= endIndex; i++)
	{
		subSequence->Add(this->buffer->Get(i));
	}
	
	return subSequence;
}
template<typename T>
queuePriority<T>* queuePriority<T>::Concatenate(queuePriority<T>* source)
{
	for (int i = 0; i<this->buffer->GetLength(); i++) 
	{
		source->Add(this->Get(i));
	}
	return source;
}
template<typename T>
bool queuePriority<T>::FindSubSequence(queuePriority<T>* exemplar) 
{
	bool finded = false;
	for (int i = 0; i < this->buffer->GetLength()-exemplar->GetLength()+1 && finded == false; i++) 
	{
		bool fail = false;
		for (int j = 0; j < exemplar->GetLength() && fail != true; j++) 
		{
			if (this->Get(i + j) != exemplar->Get(j)) fail = true;
		}
		if (fail != true) finded = true;
	}
	return finded;
}
template<typename T>
int queuePriority<T>::GetDecision()
{
	return this->decision;
}
template<typename T>
int queuePriority<T>::GetLength()
{
	return this->buffer->GetLength();
}
template<typename T>
void queuePriority<T>::Remove(int index)
{
	this->buffer->Remove(index);
}
template<typename T>
queuePriority<T>* queuePriority<T>::SplitIntoTwo(queuePriority<T>* source, bool function(T,T),T n) 
{
	for (int i = 0; i < this->GetLength(); i++) 
	{
		if (function(this->Get(i), n)) 
		{
			source->Add(this->Get(i));
			this->Remove(i);
			i--;
		}
	}
	return source;
}