#pragma once
#include <cassert>
#include "queuePriority.h"
#include <iostream>
using namespace std;
class queuePriorityTests
{
private:
	void Test_Add();
public:
	void Test();
};
void queuePriorityTests::Test_Add()
{
	int* exampleArrayPointer = new int[6]{ 3,4,6,1,5,7 };
	queuePriority<int>* example = new queuePriority<int>(1,exampleArrayPointer,6);
	example->Add(2);
	for (int i = 0; i < 7; i++) 
	{
		assert(example->Get(i)==7-i);
	}
}
void queuePriorityTests::Test() 
{
	Test_Add();
	cout << "queuePriority->work correctly" << endl;
}

