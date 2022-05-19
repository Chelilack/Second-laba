#pragma once
#include <cassert>
#include <iostream>
#include "LinkedListSequence.h"
class LinkedListSequenceTests
{
private:
	LinkedListSequence<char>* CreateExample()
	{
		char example[] = "Example";
		char* examplePointer = new char[7];
		examplePointer = example;
		LinkedListSequence<char>* result = new LinkedListSequence<char>(examplePointer,7);
		return result;
	}
	void Test_Get() 
	{
		LinkedListSequence<char>* example = CreateExample();
		assert(example->Get(0) == 'E');
		assert(example->Get(1) == 'x');
		assert(example->Get(2) == 'a');
		assert(example->Get(3) == 'm');
		assert(example->Get(4) == 'p');
		assert(example->Get(5) == 'l');
		assert(example->Get(6) == 'e');
		assert(example->GetFirst() == 'E');
		assert(example->GetLast() == 'e');
		assert(example->GetLength() == 7);
		delete example;
	}
	void Test_Set() 
	{
		LinkedListSequence<char>* example = CreateExample();

		example->InsertAt('!', 2);
		assert(example->Get(2) == '!');
		assert(example->Get(3) == 'a');
		assert(example->Get(1) == 'x');
		assert(example->GetLength() == 8);

		example = CreateExample();
		example->Append('!');
		assert(example->GetLast() == '!');
		assert(example->Get(6) == 'e');
		assert(example->GetLength() == 8);

		example = CreateExample();
		example->Prepend('@');
		assert(example->GetFirst() == '@');
		assert(example->Get(1) == 'E');
		assert(example->GetLength() == 8);

		delete example;
	}
	void Test_GetSubList() 
	{
		LinkedListSequence<char>* example = CreateExample();
		LinkedListSequence<char>* subExample = (LinkedListSequence<char>*)example->GetSubsequence(5,6);
		assert(subExample->Get(0) == 'l');

		subExample = (LinkedListSequence<char>*)example->GetSubsequence(3, 6);
		assert(subExample->Get(0) == 'm');
		assert(subExample->Get(1) == 'p');
		assert(subExample->Get(2) == 'l');
		delete subExample;
		delete example;
	}
	void Test_Concat() 
	{
		LinkedListSequence<char>* example = CreateExample();
		LinkedListSequence<char>* example1 = CreateExample();
		Sequence<char>* result =example->Concat((Sequence<char>*)example1);
		for (int i = 0; i < result->GetLength(); i++)
		{
			assert(result->Get(i) == example1->Get(i % (result->GetLength() - example1->GetLength())));
		}
		delete example;
		delete example1;
	}
	void Test_Remove() 
	{
		LinkedListSequence<char>* example = CreateExample();
		example->Remove(0);
		assert(example->GetFirst() == 'x');
		assert(example->GetLength() == 6);

		example = CreateExample();
		example->Remove(6);
		assert(example->GetLast() == 'l');
		assert(example->GetLength() == 6);

		example = CreateExample();
		example->Remove(5);
		assert(example->Get(5) == 'e');
		assert(example->GetLength() == 6);
	}
public:
	void Test()
	{
		Test_Get();
		Test_Set();
		Test_GetSubList();
		Test_Concat();
		Test_Remove();
		cout << "LinkedListSequence->work correctly" << endl;
	}

};

