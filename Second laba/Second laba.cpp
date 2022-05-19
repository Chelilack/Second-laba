#include <iostream>
#include "LinkedList.h"
#include "LinkedListTests.h"
#include "LinkedListSequenceTests.h"
#include "DynamicArrayTests.h"
#include "ArraySequenceTests.h"
#include "ArraySequence.h"
#include "LinkedListSequence.h"

#include "DynamicArray.h"
using namespace std;

int main()
{
    LinkedListTests* testList=new LinkedListTests();
    DynamicArrayTests* testArray = new DynamicArrayTests();
    LinkedListSequenceTests* testListSequence = new LinkedListSequenceTests();
    ArraySequenceTests* testArraySequence = new ArraySequenceTests();
    
    testArray->Test();
    testList->Test();
    testListSequence->Test();
    testArraySequence->Test();
    

    cout << "SecondLaba work correctly\n";
}

