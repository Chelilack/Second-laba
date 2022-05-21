#pragma once
#include <cassert>
#include <iostream>
#include "ArraySequence.h"
class ArraySequenceTests
{
private:
	ArraySequence<char>* CreateExample(const char* item)
	{
		char* example = new char[strlen(item)];
		int length = strlen(item) + 1;
		for (int i = 0; i < length; i++)
		{
			*(example + i) = *item++;
		}
		ArraySequence<char>* list = new ArraySequence<char>(example, strlen(example));
		return list;
	}
	void CheckExample(ArraySequence<char>* item, const char* correct)
	{
		for (int i = 0; i < item->GetLength(); i++)
		{
			assert(item->Get(i) == *(correct + i));
		}
		assert(item->GetLength() == strlen(correct));
	}
	void Test_Set()
	{
		ArraySequence<char>* example = CreateExample("Example");
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
	void Test_Remove()
	{
		ArraySequence<char>* example = CreateExample("Example");
		example->Remove(0);
		CheckExample(example, "xample");

		example = CreateExample("Example");
		example->Remove(2);
		CheckExample(example, "Exmple");
		
		example = CreateExample("Example");
		example->Remove(6);
		CheckExample(example, "Exampl");

		delete example;
	}
	void Test_Concat()
	{
		ArraySequence<char>* example = CreateExample("I want ");
		ArraySequence<char>* example1 = CreateExample("extra points");
		Sequence<char>* result = example->Concat((Sequence<char>*)example1);
		CheckExample((ArraySequence<char>*)result, "I want extra points");
	}
	void Test_GetSubList()
	{
		ArraySequence<char>* example = CreateExample("Example");
		ArraySequence<char>* subExample = (ArraySequence<char>*)example->GetSubsequence(5, 5);
		CheckExample(subExample, "l");
		subExample = (ArraySequence<char>*)example->GetSubsequence(5, 6);
		CheckExample(subExample, "le");

		example = CreateExample("Some peace of second laba");
		subExample = (ArraySequence<char>*)example->GetSubsequence(0, 3);
		CheckExample(subExample, "Some");
		subExample = (ArraySequence<char>*)example->GetSubsequence(0, 6);
		CheckExample(subExample, "Some pe");
		subExample = (ArraySequence<char>*)example->GetSubsequence(5, 9);
		CheckExample(subExample, "peace");
		subExample = (ArraySequence<char>*)example->GetSubsequence(21, 24);
		CheckExample(subExample, "laba");
		subExample = (ArraySequence<char>*)example->GetSubsequence(0, 24);
		CheckExample(subExample, "Some peace of second laba");
		delete subExample;
		delete example;
	}


public:
	void Test()
	{
		Test_Set();
		Test_Remove();
		Test_Concat();
		Test_GetSubList();


		cout << "ArraySequence->work correctly" << endl;
	}
};

