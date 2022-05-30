#pragma once
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;
class Teacher
{
private:
    int id;
    char* firstName;
    char* lastName;
    char* subject;

public:
    Teacher(int id, char* firstName, char* lastName, char* subject);
    Teacher();

public:
    void Input();
    void RandomInput();
    int GetId() const;
    char* GetFirstName() const;
    char* GetLastName() const;
    char* GetSubject()const;
    bool operator >(const Teacher teacher)
    {
        if (this->GetId() > teacher.GetId())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator <(const Teacher  teacher)
    {
        if (this->GetId() < teacher.GetId())
        {
           return true;
        }
        else
        {
            return false;
        }
    }
    bool operator >=(const Teacher teacher)
    {
        if (this->GetId() >= teacher.GetId())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator <=(const Teacher  teacher)
    {
        if (this->GetId() <= teacher.GetId())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator ==(const Teacher  teacher)
    {
        if (this->GetId() == teacher.GetId())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator !=(const Teacher  teacher)
    {
        if (this->GetId() != teacher.GetId())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    friend ostream& operator<<(ostream& os, const Teacher& teacher);

};
Teacher::Teacher(int id, char* firstName,  char* lastName, char* subject) : id(id), firstName(firstName), lastName(lastName) ,subject(subject){}
Teacher::Teacher() : id(NULL), firstName(NULL), lastName(NULL), subject(NULL) {}
void Teacher::Input() 
{
    char* pass=new char[32];
    cout << "ID:" << endl;
    cin >> this->id;
    cout << "First Name:" << endl;
    cin >> pass; 
    this->firstName = pass;
    pass = new char[32];
    cout << "Last Name:" << endl;
    cin >> pass;
    this->lastName = pass;
    pass = new char[32];
    cout << "Subject:" << endl;
    cin >> pass;
    this->subject = pass;
}
void Teacher::RandomInput()
{
    ifstream NameFile;
    NameFile.open("D:/опера/из гитхаба/name-generator-master/name-generator-master/resources/american/names.txt");
    ifstream LastNameFile;
    LastNameFile.open("D:/опера/из гитхаба/name-generator-master/name-generator-master/resources/american/sur.txt");
    ifstream CoursesFile;
    CoursesFile.open("D:/опера/из гитхаба/name-generator-master/name-generator-master/resources/american/courses.txt");
    int strNumber = rand() % 201 + 1;
    int strCourseNumber = rand()%50+1;
    int strNow = 0;
    char* passName = new char[20];
    char* passSur = new char[20];
    char* passCourse = new char[50];
    while (strNow != strNumber)
    {
        NameFile.getline(passName, 20, '\n');
        LastNameFile.getline(passSur,20,'\n');
        strNow++;
    }
    strNow = 0;
    while (strNow != strCourseNumber)
    {
        CoursesFile.getline(passCourse, 50, '\n');
        strNow++;
    }
    NameFile.close();
    LastNameFile.close();
    CoursesFile.close();
    this->firstName = passName;
    this->lastName = passSur;
    this->subject = passCourse;
    this->id = rand()%100000;

}
int   Teacher::GetId() const
{
    return this->id;
}
char* Teacher::GetFirstName() const
{
    return this->firstName;
}
char* Teacher::GetLastName() const
{
    return this->lastName;
}
char* Teacher::GetSubject() const 
{
    return this->subject;
}
ostream& operator<<(ostream& os, const Teacher& teacher)
{
    os << "ID: " << teacher.GetId() << "\nName: " << teacher.GetFirstName() << "\nLast Name: " << teacher.GetLastName() << "\nSubject: " << teacher.GetSubject() << endl;
    return os;
}


 