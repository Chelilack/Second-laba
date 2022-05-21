#pragma once
#include <cassert>
#include <iostream>
#include "LinkedListSequence.h"
class LinkedListSequenceTests
{
	LinkedListSequence<char>* CreateExample(const char* item)
	{
		char* example = new char[strlen(item)];
		int length = strlen(item) + 1;
		for (int i = 0; i < length; i++)
		{
			*(example + i) = *item++;
		}
		LinkedListSequence<char>* list = new LinkedListSequence<char>(example, strlen(example));
		return list;
	}
	void CheckExample(LinkedListSequence<char>* item, const char* correct)
	{
		for (int i = 0; i < item->GetLength(); i++)
		{
			assert(item->Get(i) == *(correct + i));
		}
		assert(item->GetLength() == strlen(correct));
	}
	void Test_Set() 
	{
		LinkedListSequence<char>* example = CreateExample("Example");

		example->InsertAt('!', 1);
		CheckExample(example, "E!xample");

		example = CreateExample("Example");
		example->Append('!');
		CheckExample(example, "Example!");

		example = CreateExample("Example");
		example->Prepend('@');
		CheckExample(example, "@Example");

		delete example;
	}
	void Test_GetSubList()
	{
		LinkedListSequence<char>* example = CreateExample("Example");
		LinkedListSequence<char>* subExample = (LinkedListSequence<char>*)example->GetSubsequence(5, 5);
		CheckExample(subExample, "l");
		subExample = (LinkedListSequence<char>*)example->GetSubsequence(5, 6);
		CheckExample(subExample, "le");

		example = CreateExample("Some peace of second laba");
		subExample = (LinkedListSequence<char>*)example->GetSubsequence(0, 3);
		CheckExample(subExample, "Some");
		subExample = (LinkedListSequence<char>*)example->GetSubsequence(0, 6);
		CheckExample(subExample, "Some pe");
		subExample = (LinkedListSequence<char>*)example->GetSubsequence(5, 9);
		CheckExample(subExample, "peace");
		subExample = (LinkedListSequence<char>*)example->GetSubsequence(21, 24);
		CheckExample(subExample, "laba");
		subExample = (LinkedListSequence<char>*)example->GetSubsequence(0, 24);
		CheckExample(subExample, "Some peace of second laba");
		delete subExample;
		delete example;
	}
	void Test_Concat()
	{
		LinkedListSequence<char>* example = CreateExample("I want ");
		LinkedListSequence<char>* example1 = CreateExample("extra points");
		Sequence<char>* result = example->Concat((Sequence<char>*)example1);
		CheckExample((LinkedListSequence<char>*)result,"I want extra points");
		delete example;
		delete example1;
	}
	void Test_Remove()
	{
		LinkedListSequence<char>* example = CreateExample("Example");
		example->Remove(0);
		CheckExample(example, "xample");

		example = CreateExample("Example");
		example->Remove(6);
		CheckExample(example, "Exampl");

		example = CreateExample("Example");
		example->Remove(5);
		CheckExample(example, "Exampe");
	}
public:
	void Test()
	{
		Test_Set();
		Test_GetSubList();
		Test_Concat();
		Test_Remove();
		cout << "LinkedListSequence->work correctly" << endl;
	}

};

