#pragma once
bool IntDevidedBy(int number,int delim) 
{
	return number % delim == 0;
}
bool IntIsOdd(int number,int delim)
{
	return number % delim == 1;
}
bool IntMore(int number, int n) 
{
	return number > n;
}
bool IntLess(int number, int n)
{
	return number < n;
}
bool (*IntFunctionsPtr[])(int,int) = {IntDevidedBy,IntIsOdd,IntMore,IntLess};


enum IntFunctions 
{
	EnumIntDevidedBy,
	EnumIntIsOdd,
	EnumIntMore,
	EnumIntLess,
};


bool FloatMore(float number, float n)
{
	return number > n;
}
bool FloatLess(float number, float n)
{
	return number < n;
}
bool (*FloatFunctionsPtr[])(float, float) = { FloatMore,FloatLess };
enum FloatFunctions
{
	EnumFloatMore,
	EnumFloatLess,
};


bool CharPtrInclude(char* str, char* str1)
{
	bool finded = false;
	for (int i = 0; i < strlen(str) - strlen(str1) + 1 && finded == false; i++)
	{
		bool fail = false;
		for (int j = 0; j < strlen(str1) && fail != true; j++)
		{
			if (str[i+j]!= str1[j]) fail = true;
		}
		if (fail != true) finded = true;
	}
	return finded;
}
bool CharPtrLengthMore(char* str , char* str1) 
{
	return (strlen(str) > strlen(str1));
}
bool CharPtrLengthLess(char* str , char* str1) 
{
	return (strlen(str) < strlen(str1));
}
bool (*CharPtrFunctionsPtr[])(char*, char*) = { CharPtrLengthMore,CharPtrLengthLess,CharPtrInclude };
enum CharPtrFunctions
{
	EnumCharPtrLengthMore,
	EnumCharPtrLengthLess,
	EnumCharPtrInclude,
};


bool ComplexNumberMore(ComplexNumber number, ComplexNumber n)
{
	return number > n;
}
bool ComplexNumberLess(ComplexNumber number, ComplexNumber n)
{
	return number < n;
}
bool (*ComplexNumberFunctionsPtr[])(ComplexNumber, ComplexNumber) = { ComplexNumberMore,ComplexNumberLess };
enum ComplexNumberFunctions
{
	EnumComplexNumberMore,
	EnumComplexNumberLess,
};
bool StudentIDMore(Student ID, Student n)
{
	return ID > n;
}
bool StudentIDLess(Student ID, Student n)
{
	return ID < n;
}
bool (*StudentFunctionsPtr[])(Student, Student) = { StudentIDMore,StudentIDLess };
enum StudentIDFunctions
{
	EnumStudentIDMore,
	EnumStudentIDLess,
};


bool TeacherIDMore(Teacher ID, Teacher n)
{
	return ID > n;
}
bool TeacherIDLess(Teacher ID, Teacher n)
{
	return ID < n;
}
bool (*TeacherFunctionsPtr[])(Teacher, Teacher) = { TeacherIDMore,TeacherIDLess };
enum TeacherIDFunctions
{
	EnumTeacherIDMore,
	EnumTeacherIDLess,
};
