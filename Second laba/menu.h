#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include "ArraySequenceTests.h"
#include "DynamicArrayTests.h"
#include "LinkedListTests.h"
#include "LinkedListSequenceTests.h"
#include "queuePriorityTests.h"
#include "ComplexNumber.h"
#include "Student.h"
#include "Teacher.h"
#include "queuePriority.h"
#include "Errors.h"
#include "Input.h"
#include "functions.h"

using namespace std;
void menu()
{
	queuePriority<int>* queueInt=0;
	queuePriority<float>* queueFloat = 0;
	queuePriority<char*>* queueCharPtr = 0;
	queuePriority<ComplexNumber>* queueComplexNumber=0;
	queuePriority<Student>* queueStudent=0;
	queuePriority<Teacher>* queueTeacher=0;
	int page = -1;
	auto menuExistQueue = [&]()
	{
		if (queueCharPtr==0 && queueComplexNumber==0 && queueFloat==0 && queueInt==0 && queueStudent==0 && queueTeacher==0) 
		{
			cout << "all queue empty!" << endl; 
			system("pause");
			page = -1;
			menu();
		}
		int j = 0;
		int i=1;
		int choice;
		int* data = new int[6];
		cout <<                                          "-------------------------" << endl;
		if (queueInt != 0)           { cout <<'|'<< i << ". Queue<int>          |"<< endl;i++;data[j++]=1; }
		if (queueFloat != 0)         { cout <<'|'<< i << ". Queue<float>        |"<< endl;i++;data[j++]=2; }
		if (queueCharPtr != 0)       { cout <<'|'<< i << ". Queue<char*>        |"<< endl;i++;data[j++]=3; }
		if (queueComplexNumber != 0) { cout <<'|'<< i << ". Queue<ComplexNumber>|"<< endl;i++;data[j++]=4; }
		if (queueStudent != 0)       { cout <<'|'<< i << ". Queue<Student>      |"<< endl;i++;data[j++]=5; }
		if (queueTeacher != 0)       { cout <<'|'<< i << ". Queue<Teacher>      |"<< endl;i++;data[j++]=6; }
		cout <<                                          "-------------------------" << endl;
		cin >> choice;
		return (int)data[choice-1];
	};
	
	while (page != 0)
	{
		system("cls");
		if (page == -1)
		{
			cout << "-------------------------------" << endl;
			cout << "|1.Create queue(with priority)|" << endl;
			cout << "|2.Do smth with queue         |" << endl;
			cout << "|3.Run Tests                  |" << endl;
			cout << "|0.Exit                       |" << endl;
			cout << "-------------------------------" << endl;
			cin >> page;
			while (page != 1 && page != 2 && page != 3 && page!=0 )
			{
				cout << "try again!" << endl;
				cin >> page;
			}
		}
		else if (page == 1)
		{
			system("cls");
			cout << "----------------------" << endl;
			cout << "|1. Integers         |" << endl;
			cout << "|2. Floats           |" << endl;
			cout << "|3. Complex numbers  |" << endl;
			cout << "|4. Strings          |" << endl;
			cout << "|5. Students         |" << endl;
			cout << "|6. Teachers         |" << endl;
			cout << "|0. Exit             |" << endl;
			cout << "----------------------" << endl;
			int miniPage;
			int decision;
			cin >> miniPage;
			while (miniPage != 1 && miniPage != 2 && miniPage != 3 && miniPage != 4 && miniPage != 5 && miniPage != 6 && miniPage != 0)
			{
				cout << "try again!" << endl;
				cin >> miniPage;
			}
			if (miniPage != 0) 
			{
				system("cls");
				cout << "----------------------" << endl;
				cout << "|1.ArraySequence     |" << endl;
				cout << "|2.LinkedListSequence|" << endl;
				cout << "----------------------" << endl;
				cin >> decision;
			}
			if (miniPage == 1) 
			{
				queueInt=InputIntArray(decision);
			}
			else if (miniPage == 2)
			{
				queueFloat=InputFloatArray(decision);
			}
			else if (miniPage == 3) 
			{
				queueComplexNumber=InputComplexNumberArray(decision);
			}
			else if (miniPage == 4) 
			{
				queueCharPtr=InputCharPtrArray(decision);
			}
			else if (miniPage == 5)
			{
				queueStudent=InputStudentArray(decision);
			}
			else if (miniPage == 6) 
			{
				queueTeacher = InputTeacherArray(decision);
			}
			cout << endl;
			system("pause");
			page = -1;
		}
		else if (page == 2)
		{
			cout <<"----------------------" << endl;
			cout<< "|1. Add              |" << endl;
			cout<< "|2. Get subsequence  |" << endl;
			cout<< "|3. Concatenate      |" << endl;
			cout<< "|4. Find subsequence |" << endl;
			cout<< "|5. Split into two   |" << endl;
			cout<< "|6. Print queue      |" << endl;
			cout<< "|0. Quit             |" << endl;
			cout <<"----------------------" << endl;
			int miniPage2;
			cin >> miniPage2;
			while (miniPage2 != 1 && miniPage2 != 2 && miniPage2 != 3 && miniPage2 != 4 && miniPage2 != 5 && miniPage2 != 6 && miniPage2 != 7 && miniPage2 != 0)
			{
				cout << "try again!" << endl;
				cin >> miniPage2;
			}
			if (miniPage2 == 1) 
			{

				int choice = menuExistQueue();
				if (choice == 1) 
				{ 
					int intPass; 
					cout << "Enter int:" << endl;
					cin >> intPass; 
					queueInt->Add(intPass); 
				}
				else if (choice == 2)
				{
					float floatPass;
					cout << "Enter float:" << endl;
					cin >> floatPass;
					queueFloat->Add(floatPass);
				}
				else if (choice == 3) 
				{
					char* charPtrPass=new char[64];
					cout << "Enter char*:" << endl;
					cin >> charPtrPass;
					queueCharPtr->Add(charPtrPass); 
				}
				else if (choice == 4)
				{
					ComplexNumber complexNumberPass;
					cout << "Enter Complex Number:" << endl;
					complexNumberPass.Input();
					queueComplexNumber->Add(complexNumberPass);
				}
				else if (choice == 5)
				{
					Student studentPass;
					cout << "Enter Student:" << endl;
					studentPass.Input();
					queueStudent->Add(studentPass);
				}
				else if (choice == 6)
				{
					Teacher teacherPass;
					cout << "Enter Teacher" << endl;
					teacherPass.Input();
					queueTeacher->Add(teacherPass);
				}

			}
			else if (miniPage2 == 2) 
			{
				int startIndex, endIndex;
				cout << "start Index:" << endl;
				cin >> startIndex;
				cout << "end Index:" << endl;
				cin >> endIndex ;
				int choice = menuExistQueue();
				if (choice == 1)
				{
					queueInt->GetSubsequence(startIndex,endIndex);
					queueInt->Print();
				}
				else if (choice == 2)
				{
					queueFloat->GetSubsequence(startIndex, endIndex);
					queueFloat->Print();
				}
				else if (choice == 3)
				{
					queueCharPtr->GetSubsequence(startIndex, endIndex);
					queueCharPtr->Print();
				}
				else if (choice == 4)
				{
					queueComplexNumber->GetSubsequence(startIndex, endIndex);
					queueComplexNumber->Print();
				}
				else if (choice == 5)
				{
					queueStudent->GetSubsequence(startIndex, endIndex);
					queueStudent->Print();
				}
				else if (choice == 6)
				{
					queueTeacher->GetSubsequence(startIndex, endIndex);
					queueTeacher->Print();
				}
			}
			else if (miniPage2 == 3) 
			{
			int choice = menuExistQueue();
			if (choice == 1)
			{
				queuePriority<int>* queueIntConcatenated;
				queueIntConcatenated = queueInt->Concatenate(InputIntArray(queueInt->GetDecision()));
				cout << '\n' << "result-------------" << endl;
				queueIntConcatenated->Print();
			}
			if (choice == 2)
			{
				queuePriority<float>* queueFloatConcatenated;
				queueFloatConcatenated = queueFloat->Concatenate(InputFloatArray(queueFloat->GetDecision()));
				cout << '\n' << "result-------------" << endl;
				queueFloatConcatenated->Print();
			}
			if (choice == 3)
			{
				queuePriority<char*>* queueCharPtrConcatenated;
				queueCharPtrConcatenated = queueCharPtr->Concatenate(InputCharPtrArray(queueCharPtr->GetDecision()));
				cout << '\n' << "result-------------" << endl;
				queueCharPtrConcatenated->Print();
			}
			if (choice == 4)
			{
				queuePriority<ComplexNumber>* queueComplexNumberConcatenated;
				queueComplexNumberConcatenated = queueComplexNumber->Concatenate(InputComplexNumberArray(queueComplexNumber->GetDecision()));
				cout << '\n' << "result-------------" << endl;
				queueComplexNumberConcatenated->Print();
			}
			if (choice == 5)
			{
				queuePriority<Student>* queueStudentConcatenated;
				queueStudentConcatenated = queueStudent->Concatenate(InputStudentArray(queueStudent->GetDecision()));
				cout << '\n' << "result-------------" << endl;
				queueStudentConcatenated->Print();
			}
			if (choice == 6)
			{
				queuePriority<Teacher>* queueTeacherConcatenated;
				queueTeacherConcatenated = queueTeacher->Concatenate(InputTeacherArray(queueTeacher->GetDecision()));
				cout << '\n' << "result-------------" << endl;
				queueTeacherConcatenated->Print();
			}
			}
			else if (miniPage2 == 4) 
			{
				int choice=menuExistQueue();
				if (choice == 1) 
				{
					queuePriority<int>* queueIntExemplar= InputIntArray(queueInt->GetDecision());
					cout << '\n' << "result-------------" << endl;
					if (queueInt->FindSubSequence(queueIntExemplar)) cout << "YES" << endl;
					else cout << "NO" << endl;
					
				}
				if (choice == 2)
				{
					queuePriority<float>* queueFloatExemplar= InputFloatArray(queueFloat->GetDecision());
					cout <<'\n'<<"result-------------"<< endl;
					if(queueFloat->FindSubSequence(queueFloatExemplar)) cout<<"YES"<<endl;
					else cout << "NO" << endl;
				}
				if (choice == 3)
				{
					queuePriority<char*>* queueCharPtrExemplar= InputCharPtrArray(queueCharPtr->GetDecision());
					cout <<'\n'<<"result-------------"<< endl;
					if(queueCharPtr->FindSubSequence(queueCharPtrExemplar)) cout<<"YES"<<endl;
					else cout << "NO" << endl;
				}
				if (choice == 4)
				{
					queuePriority<ComplexNumber>* queueComplexNumberExemplar= InputComplexNumberArray(queueComplexNumber->GetDecision());
					cout <<'\n'<<"result-------------"<< endl;
					if(queueComplexNumber->FindSubSequence(queueComplexNumberExemplar)) cout<<"YES"<<endl;
					else cout << "NO" << endl;
				}
				if (choice == 5)
				{
					queuePriority<Student>* queueStudentExemplar= InputStudentArray(queueStudent->GetDecision());
					cout <<'\n'<<"result-------------"<< endl;
					if(queueStudent->FindSubSequence(queueStudentExemplar)) cout<<"YES"<<endl;
					else cout << "NO" << endl;
				}
				if (choice == 6)
				{
					queuePriority<Teacher>* queueTeacherExemplar= InputTeacherArray(queueTeacher->GetDecision());
					cout <<'\n'<<"result-------------"<< endl;
					if(queueTeacher->FindSubSequence(queueTeacherExemplar)) cout<<"YES"<<endl;

				}
			}
			else if (miniPage2 == 5)
			{
				int choice = menuExistQueue();
				
				if (choice == 1)
				{
					queuePriority<int>* SecondqueueInt = new queuePriority<int>(queueInt->GetDecision());
					int miniChoice = 0;
					int n;
					cout << "1.Divide by n" << endl;
					cout << "2.even/odd" << endl;
					cout << "3.more/less than n" << endl;
					cin >> miniChoice;
					while (miniChoice != 1 && miniChoice != 2 && miniChoice != 3)
					{
						cout << "try again" << endl;
						cin >> miniChoice;
					}
					if (miniChoice == 1)
					{
						cout << "Enter n:" << endl;
						cin >> n;
						queueInt->SplitIntoTwo(SecondqueueInt,IntFunctionsPtr[EnumIntDevidedBy],n);
					}
					else if (miniChoice == 2)
					{
						cout << "1.even" << endl;
						cout << "2.odd" << endl;
						cin >> n;
						while (n != 1 && n != 2)
						{
							cout << "try again" << endl;
							cin >> n;
						}
						if (n == 1)
						{
							queueInt->SplitIntoTwo(SecondqueueInt,IntFunctionsPtr[EnumIntDevidedBy],n);

						}
						else if (n == 2)
						{
							queueInt->SplitIntoTwo(SecondqueueInt,IntFunctionsPtr[EnumIntIsOdd],n);
						}
					}
					else if (miniChoice == 3)
					{
						cout << "1.More" << endl;
						cout << "2.Less" << endl;
						cin >> n;
						while (n != 1 && n != 2)
						{
							cout << "try again" << endl;
							cin >> n;
						}
						cout << "Enter n:" << endl;
						int number;
						cin >> number;
						if (n == 1)
						{
							queueInt->SplitIntoTwo(SecondqueueInt, IntFunctionsPtr[EnumIntMore], number);

						}
						else if (n == 2)
						{
							queueInt->SplitIntoTwo(SecondqueueInt, IntFunctionsPtr[EnumIntLess], number);
						}
					}
					cout << "First queue(False)" << endl;
					queueInt->Print();
					cout << endl;
					cout << "Second queue(True)" << endl;
					SecondqueueInt->Print();
					cout << endl;
				}
				if (choice == 2)
				{
					queuePriority<float>* SecondqueueFloat=new queuePriority<float>(queueFloat->GetDecision());
					int miniChoice = 0;
					int n;
					cout << "1.more/less than n" << endl;
					cin >> miniChoice;
					while (miniChoice != 1)
					{
						cout << "try again" << endl;
						cin >> miniChoice;
					}
					if (miniChoice == 1)
					{
						cout << "1.More" << endl;
						cout << "2.Less" << endl;
						cin >> n;
						while (n != 1 && n != 2)
						{
							cout << "try again" << endl;
							cin >> n;
						}
						cout << "Enter n:" << endl;
						float number;
						cin >> number;
						if (n == 1)
						{
							queueFloat->SplitIntoTwo(SecondqueueFloat, FloatFunctionsPtr[EnumFloatMore], number);

						}
						else if (n == 2)
						{
							queueFloat->SplitIntoTwo(SecondqueueFloat, FloatFunctionsPtr[EnumFloatLess], number);
						}
						cout << "First queue(False)" << endl;
						queueFloat->Print();
						cout << endl;
						cout << "Second queue(True)" << endl;
						SecondqueueFloat->Print();
						cout << endl;
					}
				}
				if (choice == 3)
				{
					queuePriority<char*>* SecondqueueCharPtr = new queuePriority<char*>(queueCharPtr->GetDecision());
					int miniChoice = 0;
					int n;
					cout << "1.Length more/less than n" << endl;
					cout << "2.Check for inclusion" << endl;
					cin >> miniChoice;
					while (miniChoice != 1 && miniChoice!=2)
					{
						cout << "try again" << endl;
						cin >> miniChoice;
					}
					if (miniChoice == 1)
					{
						cout << "1.More" << endl;
						cout << "2.Less" << endl;
						cin >> n;
						while (n != 1 && n != 2)
						{
							cout << "try again" << endl;
							cin >> n;
						}
						cout << "Enter n:" << endl;
						int length;
						cin >> length;
						char* str = new char[32];
						for (int i = 0; i < length; i++) { str[i] = 'a'; }
						str[length] = '\0';
						if (n == 1)
						{

							queueCharPtr->SplitIntoTwo(SecondqueueCharPtr, CharPtrFunctionsPtr[EnumCharPtrLengthMore], str);

						}
						else if (n == 2)
						{
							queueCharPtr->SplitIntoTwo(SecondqueueCharPtr, CharPtrFunctionsPtr[EnumCharPtrLengthLess], str);
						}
						
					}
					else if(miniChoice==2)
					{
						cout << "Enter str:" << endl;
						char* str = new char[32];
						cin >> str;
						queueCharPtr->SplitIntoTwo(SecondqueueCharPtr, CharPtrFunctionsPtr[EnumCharPtrInclude], str);
					}
					cout << "First queue(False)" << endl;
					queueCharPtr->Print();
					cout << endl;
					cout << "Second queue(True)" << endl;
					SecondqueueCharPtr->Print();
					cout << endl;
				}
				if (choice == 4)
				{
					queuePriority<ComplexNumber>* SecondqueueComplexNumber=new queuePriority<ComplexNumber>(queueComplexNumber->GetDecision());
					int miniChoice = 0;
					int n;
					cout << "1.more/less than n" << endl;
					cin >> miniChoice;
					while (miniChoice != 1)
					{
						cout << "try again" << endl;
						cin >> miniChoice;
					}
					if (miniChoice == 1)
					{
						cout << "1.More" << endl;
						cout << "2.Less" << endl;
						cin >> n;
						while (n != 1 && n != 2)
						{
							cout << "try again" << endl;
							cin >> n;
						}
						cout << "Enter n:" << endl;
						ComplexNumber number;
						number.Input();
						if (n == 1)
						{
							queueComplexNumber->SplitIntoTwo(SecondqueueComplexNumber, ComplexNumberFunctionsPtr[EnumComplexNumberMore], number);

						}
						else if (n == 2)
						{
							queueComplexNumber->SplitIntoTwo(SecondqueueComplexNumber, ComplexNumberFunctionsPtr[EnumComplexNumberLess], number);
						}
						cout << "First queue(False)" << endl;
						queueComplexNumber->Print();
						cout << endl;
						cout << "Second queue(True)" << endl;
						SecondqueueComplexNumber->Print();
						cout << endl;
					}

				}
				if (choice == 5)
				{
					queuePriority<Student>* SecondqueueStudent = new queuePriority<Student>(queueStudent->GetDecision());
					int miniChoice = 0;
					int n;
					cout << "1.ID more/less than n" << endl;
					cin >> miniChoice;
					while (miniChoice != 1)
					{
						cout << "try again" << endl;
						cin >> miniChoice;
					}
					if (miniChoice == 1)
					{
						cout << "1.More" << endl;
						cout << "2.Less" << endl;
						cin >> n;
						while (n != 1 && n != 2)
						{
							cout << "try again" << endl;
							cin >> n;
						}
						cout << "Enter Id :" << endl;
						int id;
						cin>>id;
						Student exemplar = Student(id, NULL, NULL);
						if (n == 1)
						{
							queueStudent->SplitIntoTwo(SecondqueueStudent, StudentFunctionsPtr[EnumStudentIDMore], exemplar );

						}
						else if (n == 2)
						{
							queueStudent->SplitIntoTwo(SecondqueueStudent, StudentFunctionsPtr[EnumStudentIDLess], exemplar );
						}
						cout << "First queue(False)" << endl;
						queueStudent->Print();
						cout << endl;
						cout << "Second queue(True)" << endl;
						SecondqueueStudent->Print();
						cout << endl;
					}

				}
				if (choice == 6)
				{
					queuePriority<Teacher>* SecondqueueTeacher=new queuePriority<Teacher>(queueTeacher->GetDecision());
					int miniChoice = 0;
					int n;
					cout << "1.ID more/less than n" << endl;
					cin >> miniChoice;
					while (miniChoice != 1)
					{
						cout << "try again" << endl;
						cin >> miniChoice;
					}
					if (miniChoice == 1)
					{
						cout << "1.More" << endl;
						cout << "2.Less" << endl;
						cin >> n;
						while (n != 1 && n != 2)
						{
							cout << "try again" << endl;
							cin >> n;
						}
						cout << "Enter Id :" << endl;
						int id;
						cin >> id;
						Teacher exemplar = Teacher(id, NULL, NULL,NULL);
						if (n == 1)
						{
							queueTeacher->SplitIntoTwo(SecondqueueTeacher, TeacherFunctionsPtr[EnumTeacherIDMore], exemplar);

						}
						else if (n == 2)
						{
							queueTeacher->SplitIntoTwo(SecondqueueTeacher, TeacherFunctionsPtr[EnumTeacherIDLess], exemplar);
						}
						cout << "First queue(False)" << endl;
						queueTeacher->Print();
						cout << endl;
						cout << "Second queue(True)" << endl;
						SecondqueueTeacher->Print();
						cout << endl;
					}
				}
			}
			else if (miniPage2 == 6)
			{
				int choice = menuExistQueue();
				if (choice==1) queueInt->Print();
				if (choice==2) queueFloat->Print();
				if (choice==3) queueCharPtr->Print();
				if (choice==4) queueComplexNumber->Print();
				if (choice==5) queueStudent->Print();
				if (choice==6) queueTeacher->Print();
			}
			cout << endl;
			system("pause");

			page = -1;
		}
		else if (page == 3)
		{
			LinkedListTests* testList = new LinkedListTests();
			DynamicArrayTests* testArray = new DynamicArrayTests();
			LinkedListSequenceTests* testListSequence = new LinkedListSequenceTests();
			ArraySequenceTests* testArraySequence = new ArraySequenceTests();
			queuePriorityTests* testQueuePriority = new queuePriorityTests();
			testQueuePriority->Test();
			std::this_thread::sleep_for(400ms);
			testArray->Test();
			std::this_thread::sleep_for(400ms);
			testList->Test();
			std::this_thread::sleep_for(400ms);
			testListSequence->Test();
			std::this_thread::sleep_for(400ms);
			testArraySequence->Test();
			std::this_thread::sleep_for(400ms);
			cout << "SecondLaba work correctly\n";
			system("pause");
			page = -1;
		}

	}
}