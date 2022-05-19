#pragma once
#include <cassert>
#include "LinkedList.h"
#include <iostream>
using namespace std;
class LinkedListTests
{

	

private:
	LinkedList<char>* CreateExample() 
	{
		
		char example[] = "Example";
		char* examplePointer = new char[7];
		examplePointer= example;
		
		LinkedList<char>* list = new LinkedList<char>(example,7);
		return list;
	}
	void Test_Get() 
	{
		LinkedList<char>* example =CreateExample();
		assert(example->Get(0)=='E');
		assert(example->Get(1)=='x');
		assert(example->Get(2)=='a');
		assert(example->Get(3)=='m');
		assert(example->Get(4)=='p');
		assert(example->Get(5)=='l');
		assert(example->Get(6)=='e');
		assert(example->GetFirst()== 'E');
		assert(example->GetLast() == 'e');
		assert(example->GetLength() == 7);
		delete example;
	}
	void Test_Set() 
	{
		LinkedList<char>* example = CreateExample();
		
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
		LinkedList<char>* example = CreateExample();
		LinkedList<char>* subExample = example->GetSubList(5,6);
		assert(subExample->Get(0) == 'l');
		assert(subExample->Get(1) == 'e');
		delete subExample;
		delete example;
	}
	void Test_Concat()
	{
		LinkedList<char>* example = CreateExample();
		LinkedList<char>* example1 = CreateExample();
		example=example->Concat(example1);
		for (int i = 0; i < example->GetLength(); i++) 
		{
			assert(example->Get(i)== example1->Get(i%(example->GetLength()- example1->GetLength())));
		}
		delete example;
		delete example1;
	}
	void Test_Remove()
	{
		LinkedList<char>* example = CreateExample();
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
		cout << "LinkedList->work correctly"<< endl;
	}
};

