#include "stdafx.h"
#include "Teacher.h"
#include <iostream>

Teacher::Teacher()
{
}
Teacher::Teacher(char* name, int age, long jobNumber, int taughtAge) {
	this->name = name;
	this->age = age;
	this->jobNumber = jobNumber;
	this->taughtAge = taughtAge;
}

void Teacher::SetJobNumber(long jobNUmber) {
	this->jobNumber = jobNUmber;
}

void Teacher::SetTaughtAge(int taughtAge) {
	this->taughtAge = taughtAge;
}

void Teacher::ShowInformation() {
	std::cout << "<--教师信息-->" << std::endl;
	Person::ShowInformation();
	std::cout << "工号：" << this->jobNumber << std::endl;
	std::cout << "教龄：" << this->taughtAge << std::endl;
}