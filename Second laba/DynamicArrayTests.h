#pragma once
#include"DynamicArray.h"
#include <cassert>
#include <iostream>
using namespace std;
class DynamicArrayTests
{
private:
	DynamicArray<char>* CreateExample()
	{
		char example[] = "Example";
		char* examplePointer = new char[7];
		examplePointer = example;
		DynamicArray<char>* answer = new DynamicArray<char>(examplePointer, 7);
		return answer;
	}
	void Test_Get() 
	{
		DynamicArray<char>* example = CreateExample();
		assert(example->Get(0)=='E');
		assert(example->Get(6)=='e');
		assert(example->Get(2)=='a');

		assert(example->GetCount() == 7);
		assert(example->GetSize() == 14);
		delete example;

	}
	void Test_Set()
	{
		DynamicArray<char>* example = CreateExample();
		example->Set(0, ')');
		assert(example->Get(0) == ')');
		assert(example->GetCount() == 8);
		assert(example->GetSize() == 14);
		
		example = CreateExample();
		example->Set(6, 'u');
		assert(example->Get(6) == 'u');
		assert(example->GetCount() == 8);
		assert(example->GetSize() == 14);
		
		example = CreateExample();
		example->Set(2, 'r');
		assert(example->Get(2) == 'r');
		assert(example->GetCount() == 8);
		assert(example->GetSize() == 14);

		delete example;
	}
	void Test_Remove()
	{
		DynamicArray<char>* example = CreateExample();
		
		example->Remove(0);
		assert(example->Get(0) == 'x');
		assert(example->GetCount() == 6);
		assert(example->GetSize() == 14);

		example = CreateExample();
		example->Remove(2);
		assert(example->Get(2) == 'm');
		assert(example->GetCount() == 6);
		assert(example->GetSize() == 14);



		delete example;
	}
	void Test_Resize()
	{
		DynamicArray<char>* example = CreateExample();
		example->Resize(3);
		assert(example->Get(0) == 'E');
		assert(example->Get(1) == 'x');
		assert(example->Get(2) == 'a');
		assert(example->GetCount() == 3);
		assert(example->GetSize() ==3 );

		delete example;
	}
public:
	void Test()
	{
		Test_Get();
		Test_Set();
		Test_Remove();
		Test_Resize();
		cout << "DynamicArray->work correctly" << endl;
	}
};

