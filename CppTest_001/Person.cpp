#include "stdafx.h"
#include "Person.h"
#include <iostream>

Person::Person()
{
}
Person::Person(int age) {
	this->age = age;
}
Person::Person(char* name) {
	this->name = name;
}
Person::Person(MyString name) {
	this->name = name;
}
Person::Person(char* name, int age) {
	this->name = name;
	this->age = age;

	std::cout << "Person被构造" << std::endl;
}
Person::Person(MyString name, int age) {
	this->name = name;
	this->age = age;
}



void Person::SetName(char* name) {
	this->name = name;
}

void Person::SetName(MyString name) {
	this->name = name;
}

void Person::SetAge(int age) {
	this->age = age;
}

void Person::ShowInformation() {
	std::cout << "姓名：" << this->name << std::endl;
	std::cout << "年龄：" << this->age << std::endl;
}