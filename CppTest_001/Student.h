#pragma once
#include "Person.h"
#include "MyString.h"
class Student :	public Person
{
protected:
	MyString _class;
	long stuNumber;
public:
	Student();
	Student(char*, int, char*, long);

	void SetClass(char*);
	void SetClass(MyString);

	void SetStuNumber(long);


	void ShowInformation();

};

