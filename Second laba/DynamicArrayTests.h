#pragma once
#include"DynamicArray.h"
#include <cassert>
#include <iostream>
using namespace std;
class DynamicArrayTests
{
private:
	DynamicArray<char>* CreateExample(const char* item)
	{
		char* example = new char[strlen(item)];
		int length = strlen(item) + 1;
		for (int i = 0; i < length; i++)
		{
			*(example + i) = *item++;
		}
		DynamicArray<char>* list = new DynamicArray<char>(example, strlen(example));
		return list;
	}
	void CheckExample(DynamicArray<char>* item, const char* correct)
	{
		for (int i = 0; i < item->GetCount(); i++)
		{
			assert(item->Get(i) == *(correct + i));
		}
		assert(item->GetCount() == strlen(correct));
	}
	void Test_Set()
	{
		DynamicArray<char>* example = CreateExample("Example");
		example->Set(1,'!');
		CheckExample(example, "E!xample");

		example = CreateExample("Example");
		example->Set(6, '!');
		CheckExample(example, "Exampl!e");

		example = CreateExample("Example");
		example->Set(0,'@');
		CheckExample(example, "@Example");

		delete example;
	}
	void Test_Remove()
	{
		DynamicArray<char>* example = CreateExample("Example");

		example->Remove(0);
		CheckExample(example,"xample");
		

		example = CreateExample("Example");
		example->Remove(2);
		CheckExample(example, "Exmple");

		example = CreateExample("Example");
		example->Remove(6);
		CheckExample(example, "Exampl");


		delete example;
	}
	void Test_Resize()
	{
		DynamicArray<char>* example = CreateExample("Example");
		example->Resize(3);
		CheckExample(example, "Exa");
		delete example;
	}
	void Test_Errors() 
	{
		DynamicArray<char>* example = CreateExample("Example");
		example->Get(-1);
		example->Get(20);
		example->Set(-1,'G');
		example->Set(20,'G');
		example->Resize(-1);
		example->Resize(0);
		example->Remove(20);
		example->Remove(-1);
	}
public:
	void Test()
	{
		
		Test_Set();
		Test_Remove();
		Test_Resize();
		//Test_Errors();
		cout << "DynamicArray->work correctly" << endl;
	}
};

