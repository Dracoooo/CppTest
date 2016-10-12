#include "stdafx.h"
#include "Student.h"
#include <iostream>

Student::Student()
{

}

Student::Student(char* name, int age, char* _class, long stuNumber) {
	this->name = name;
	this->age = age;
	this->_class = _class;
	this->stuNumber = stuNumber;
}

void Student::SetClass(char * _class) {
	this->_class = _class;
}

void Student::SetClass(MyString _class) {
	this->_class = _class;

}

void Student::SetStuNumber(long stuNumber) {
	this->stuNumber = stuNumber;
}

void Student::ShowInformation() {
	std::cout << "<--学生信息-->" << std::endl;
	Person::ShowInformation();
	std::cout << "班级：" << this->_class << std::endl;
	std::cout << "学号：" << this->stuNumber << std::endl;
}