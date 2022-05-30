#pragma once
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;
class Student
{
private:
    int id;
    char* firstName;
    char* lastName;

public:
    Student(int id, char* firstName, char* lastName);
    Student();

public:
    void RandomInput();
    void Input();
    int GetId() const; 
    char* GetFirstName() const; 
    char* GetLastName() const; 
    bool operator >(const Student student)
    {
        if (this->GetId() > student.GetId())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator <=(const Student student)
    {
        if (this->GetId() <= student.GetId())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator >=(const Student student)
    {
        if (this->GetId() >= student.GetId())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator <(const Student student)
    {
        if (this->GetId() < student.GetId())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator ==(const Student student)
    {
        if (this->GetId() == student.GetId())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator !=(const Student student)
    {
        if (this->GetId() != student.GetId())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    friend ostream& operator<<(ostream& os, const Student& dt);
};
Student::Student(int id, char* firstName, char* lastName) : id(id), firstName(firstName), lastName(lastName) {}
Student::Student() : id(0), firstName(NULL), lastName(NULL) {}
void Student::RandomInput()
{
    ifstream NameFile;
    NameFile.open("D:/опера/из гитхаба/name-generator-master/name-generator-master/resources/american/names.txt");
    ifstream LastNameFile;
    LastNameFile.open("D:/опера/из гитхаба/name-generator-master/name-generator-master/resources/american/sur.txt");
    int strNumber = rand() % 201 + 1;
    int strNow = 0;
    char* passName = new char[20];
    char* passSur = new char[20];
    while (strNow != strNumber)
    {
        NameFile.getline(passName, 20, '\n');
        LastNameFile.getline(passSur, 20, '\n');
        strNow++;
    }
    NameFile.close();
    LastNameFile.close();
    this->firstName = passName;
    this->lastName = passSur;
    this->id = rand() % 100000;

}
void Student::Input() 
{
    char* pass = new char[32];
    cout << "ID:" << endl;
    cin >> this->id;
    cout << "First Name:" << endl;
    cin >> pass;
    this->firstName = pass;
    pass = new char[32];
    cout << "Last Name:" << endl;
    cin >> pass;
    this->lastName = pass;
}
int   Student::GetId() const 
{ 
    return this->id; 
}
char* Student::GetFirstName() const 
{
    return this->firstName;
}
char* Student::GetLastName() const 
{ 
    return this->lastName; 
}
ostream& operator<<(ostream& os, const Student& student)
{
    os << "ID: " << student.GetId() << "\nName: " << student.GetFirstName() << "\nLast Name: " << student.GetLastName()<< endl;
    return os;
}
