// MyFirstCppTest_001.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <climits>
#include "MyString.h"
#include "Student.h"
#include "Teacher.h"

int main()
{
	using namespace std;

	/*MyString�����*/
	//char a[] = "helloworld";
	//MyString b= "ABCDEFG";
	//MyString test{ a };
	//cout << "Length()\t\t\t" << test.Length() << endl;
	//cout << "ToString()\t\t\t" << test.ToString() << endl;
	//cout << "Strcat(b)\t\t\t" << test.Strcat(b) << endl;
	//cout << "Strncat(b,2)\t\t\t" << test.Strncat(b, 2) << endl;
	//cout << "GetChar(5)\t\t\t" << test.GetChar(5) << endl;
	//cout << "ComparTo()\t\t\t" << test.CompareTo(b) << endl;
	//cout << "ComparTo(\"helloworldABCDEFGAB\")\t" << test.CompareTo("helloworldABCDEFGAB") << endl;
	//cout << "ComparTo(\"zel\")\t\t\t" << test.CompareTo("zel") << endl;
	//cout << "Repalce(l,Z)\t\t\t" << test.Replace('l', 'Z') << endl;
	//cout << "Insert()\t\t\t" << test.Insert(b, 2) << endl;
	//cout << "Length()\t\t\t" << test.Length() << endl;
	//cout << "SubString(2)\t\t\t" << test.SubString(2) << endl;
	//cout << "Length()\t\t\t" << test.Length() << endl;
	//cout << "SubString(9,12)\t\t\t" << test.SubString(9, 12) << endl;
	//cout << "Length()\t\t\t" << test.Length() << endl;
	//cout << test << endl;
	//test=test+"hello";
	//cout << test << endl;
	//test="helloworld";
	//cout << test << endl;
	//cout << "Length()\t\t\t" << test.Length() << endl;

	cout << "Student��Teacher��չʾģ��" <<endl;

	Student s1{"Tom",18, "class1",311500000 };
	s1.ShowInformation();
	
	cout << endl;

	Teacher t1{ "Jom",20,123456789,2 };
	t1.ShowInformation();

	cout << endl;
	char pData[20];
	int nData;
	Student stu;
	cout << "������ѧ��������  " <<endl;
	cin.getline(pData,20);
	stu.SetName(pData);
	cout << "������ѧ�����䣺  " << endl;
	cin >> nData;
	stu.SetAge(nData);
	cin.get();
	cout << "������ѧ���༶��  " << endl;
	cin.getline(pData, 20);
	stu.SetClass(pData);
	cout << "������ѧ��ѧ�ţ�  " << endl;
	cin >> nData;
	stu.SetStuNumber(nData);
	cin.get();
	cout << endl;
	stu.ShowInformation();

	cout << endl;
	cin.clear();
	cin.sync();

	Teacher tea;
	cout << "�������ʦ������  " << endl;
	cin.getline(pData, 20);
	tea.SetName(pData);
	cout << "�������ʦ���䣺  " << endl;
	cin >> nData;
	tea.SetAge(nData);
	cin.get();
	cout << "�������ʦ���ţ�  " << endl;
	cin >> nData;
	tea.SetJobNumber(nData);
	cout << "�������ʦ���䣺  " << endl;
	cin >> nData;
	tea.SetTaughtAge(nData);
	cout << endl;
	tea.ShowInformation();




	return 0;
}

