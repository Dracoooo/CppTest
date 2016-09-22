#pragma once
#include "Person.h"
class Teacher :	public Person
{
protected:
	long int jobNumber;
	int taughtAge;

public:
	Teacher();
	~Teacher();
};

