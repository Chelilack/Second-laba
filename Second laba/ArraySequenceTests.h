#pragma once
#include <cassert>
#include <iostream>
#include "ArraySequence.h"
class ArraySequenceTests
{
private:
	ArraySequence<char>* CreateExample()
	{
		char example[] = "Example";
		char* examplePointer = new char[7];
		examplePointer = example;
		ArraySequence<char>* result = new ArraySequence<char>(examplePointer, 7);
		return result;
	}
	void Test_Get()
	{
		ArraySequence<char>* example = CreateExample();
		assert(example->Get(0) == 'E');
		assert(example->Get(6) == 'e');
		assert(example->Get(2) == 'a');

		assert(example->GetLength()== 7);
		delete example;

	}
	void Test_Set()
	{
		ArraySequence<char>* example = CreateExample();
		example->InsertAt(0, ')');
		assert(example->Get(0) == ')');
		assert(example->GetLength() == 8);

		example = CreateExample();
		example->InsertAt(6, 'u');
		assert(example->Get(6) == 'u');
		assert(example->GetLength() == 8);

		example = CreateExample();
		example->InsertAt(2, 'r');
		assert(example->Get(2) == 'r');
		assert(example->GetLength() == 8);
		delete example;
	}
	void Test_Remove()
	{
		ArraySequence<char>* example = CreateExample();

		example->Remove(0);
		assert(example->Get(0) == 'x');
		assert(example->GetLength() == 6);

		example = CreateExample();
		example->Remove(2);
		assert(example->Get(2) == 'm');
		assert(example->GetLength() == 6);

		delete example;
	}
	void Test_Concat()
	{
		ArraySequence<char>* example = CreateExample();
		ArraySequence<char>* example1 = CreateExample();
		Sequence<char>* result = example->Concat((Sequence<char>*)example1);
		for (int i = 0; i < result->GetLength(); i++)
		{
			assert(result->Get(i) == example1->Get(i % (result->GetLength() - example1->GetLength())));
		}
		delete example;
		delete example1;
	}
	void Test_GetSubList()
	{
		ArraySequence<char>* example = CreateExample();
		ArraySequence<char>* subExample = (ArraySequence<char>*)example->GetSubsequence(5, 6);
		assert(subExample->Get(0) == 'l');

		subExample = (ArraySequence<char>*)example->GetSubsequence(3, 6);
		assert(subExample->Get(0) == 'm');
		assert(subExample->Get(1) == 'p');
		assert(subExample->Get(2) == 'l');
		delete subExample;
		delete example;
	}


public:
	void Test()
	{
		Test_Get();
		Test_Set();
		Test_Remove();
		Test_Concat();
		Test_GetSubList();


		cout << "ArraySequence->work correctly" << endl;
	}
};

