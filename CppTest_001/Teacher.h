#pragma once
#include "Person.h"
class Teacher :	public Person
{
protected:
	
	long jobNumber;
	int taughtAge;

public:
	Teacher();
	Teacher(char*, int, long, int);

	void SetJobNumber(long);

	void SetTaughtAge(int);

	void ShowInformation();
};

