#pragma once
#include <cassert>
#include "LinkedList.h"
#include <iostream>
using namespace std;
class LinkedListTests
{

	

private:
	LinkedList<char>* CreateExample(const char* item)
	{
		char* example=new char[strlen(item)];
		int length = strlen(item)+1;
		for (int i = 0; i <length; i++) 
		{
			*(example+i) = *item++;
		}
		LinkedList<char>* list = new LinkedList<char>(example, strlen(example));
		return list;
	}
	void CheckExample(LinkedList<char>* item,const char* correct)
	{
		for (int i = 0; i < item->GetLength(); i++) 
		{
			assert(item->Get(i) == *(correct+i));
		}
		assert(item->GetLength() == strlen(correct));
	}
	void Test_Set() 
	{
		LinkedList<char>* example = CreateExample("Example");
		example->InsertAt('!', 2);
		CheckExample(example, "Ex!ample");

		example = CreateExample("Example");
		example->InsertAt('!', 1);
		CheckExample(example, "E!xample");
		
		example = CreateExample("Example");
		example->InsertAt('!', 6);
		CheckExample(example, "Exampl!e");
 
		example = CreateExample("ice lab");
		example->Append('a');
		CheckExample(example,"ice laba");
		example->Prepend('N');
		CheckExample(example, "Nice laba");

		delete example;
	}
	void Test_GetSubList() 
	{
		LinkedList<char>* example = CreateExample("Some peace of second laba");
		LinkedList<char>* subExample = example->GetSubList(0,3);
		CheckExample(subExample, "Some");
		subExample = example->GetSubList(0, 6);
		CheckExample(subExample, "Some pe");
		subExample = example->GetSubList(5, 9);
		CheckExample(subExample, "peace");
		subExample = example->GetSubList(21, 24);
		CheckExample(subExample, "laba");
		subExample = example->GetSubList(0, 24);
		CheckExample(subExample, "Some peace of second laba");
		delete subExample;
		delete example;
	}
	void Test_Concat()
	{
		LinkedList<char>* example = CreateExample("I want ");
		LinkedList<char>* example1 = CreateExample("extra points");
		example=example->Concat(example1);
		CheckExample(example,"I want extra points");
		delete example;
		delete example1;
	}
	void Test_Remove()
	{
		LinkedList<char>* example = CreateExample("Example");
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
		cout << "LinkedList->work correctly"<< endl;
	}
};

