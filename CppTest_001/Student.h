#pragma once
#include "Person.h"
#include "MyString.h"
class Student :	public Person
{
protected:
	MyString _class;
	long int stuNumber;
public:
	Student();
	~Student();
};

