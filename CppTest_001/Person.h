#pragma once
#include "MyString.h"
class Person
{
protected:
	MyString name;
	int age;
public:
	Person();
	Person(int);
	Person(char*);
	Person(char*,int);
	Person(MyString);
	Person(MyString, int);

	void SetName(char*);
	void SetName(MyString);

	void SetAge(int);

	void ShowInformation();
};

