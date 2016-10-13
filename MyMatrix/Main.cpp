// Main.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "MyMatrix.h"
#include <cmath>
#include <iostream>

int main()
{
	using namespace std;

#pragma region 3*3����������ʾ

	cout << "����m1���£�" << endl;
	MyMatrix m1{ 3,3 };
	m1[0][0] = 1;  m1[0][1] = 2;  m1[0][2] = 3;
	m1[1][0] = 4;  m1[1][1] = 5;  m1[1][2] = 6;
	m1[2][0] = 7;  m1[2][1] = 8;  m1[2][2] = 9;
	m1.Output();

	cout << endl << "*****����*****" << endl;
	cout << "������ľ���m2���" << endl;
	MyMatrix m2{ 3,3 };
	m2[0][0] = 0;    m2[0][1] = 0;  m2[0][2] = 7;
	m2[1][0] = 6;   m2[1][1] = 3;  m2[1][2] = 5;
	m2[2][0] = 10;  m2[2][1] = 4;  m2[2][2] = 11;
	m2.Output();

	m1 -= m2;
	cout << "�õ����µ�m1����Ϊ��" << endl;
	m1.Output();

	cout << endl << "*****������ʽ*****" << endl;
	cout << "m1���������ʽ��ֵΪ�� " << m1.GetDet() << endl;

	cout << endl << "*****�˳���*****" << endl;
	cout << "m1�������4�ã� " << endl;
	m1 *= 4;
	m1.Output();

	cout << endl << "*****������*****" << endl;
	cout << "m1�������2�ã� " << endl;
	m1 /= 2;
	m1.Output();

	cout << endl << "*****�˾���*****" << endl;
	cout << "m1������Ծ���m4�� " << endl;
	MyMatrix m4{ 3,3 };
	m4[0][0] = 1;  m4[0][1] = 1;  m4[0][2] = 1;
	m4[1][0] = 0;  m4[1][1] = 1;  m4[1][2] = 1;
	m4[2][0] = 0;  m4[2][1] = 0;  m4[2][2] = 1;
	m4.Output();

	m1 *= m4;
	cout << "�õ����µ�m1����Ϊ��" << endl;
	m1.Output();

	cout << endl << "*****�ӷ�*****" << endl;
	cout << "������ľ���m3��ӣ�" << endl;
	MyMatrix m3{ 3,3 };
	m3[0][0] = -1;  m3[0][1] = -4;  m3[0][2] = 5;
	m3[1][0] = 6;  m3[1][1] = 2;  m3[1][2] = -1;
	m3[2][0] = 9;  m3[2][1] = 2;  m3[2][2] = 5;
	m3.Output();

	m1 += m3;
	cout << "�õ����µ�m1����Ϊ��" << endl;
	m1.Output();

	cout << endl << "*****�������*****" << endl;
	m1.Inverse();
	cout << "����m1�����ľ������£�" << endl;
	m1.Output();

	cout << endl << endl << "���沿��Ϊm*n�������е�3*3������ʾ����" << endl;
	cout << "**************************************" << endl;

#pragma endregion

#pragma region m*n��������ϵͳ

	cout << endl << "**************************************" << endl;
	cout << "*********  m*n��������ϵͳ  **********" << endl;
	cout << "**************************************" << endl << endl;

	while (true) {
		bool bQuit = false; 

		cout << "����m*n������ֱ�����������������" << endl;
		int row, col;
		cin >> row >> col;
		MyMatrix mc{ row,col };
		mc.Create();
		cout << endl << "**************************************" << endl;
		cout << "�������" << row << "*" << col << "�����������£�" << endl;
		mc.Output();
		cout << "**************************************" << endl;
		cout << "��ѡ����Ҫ���еĲ�����" << endl;

#pragma region �˵���ʾ

		//ֻ��n�׾����������ʽ������
		if (row == col) {
			cout << "(1)��ͬ�;�����ӣ�" << endl;
			cout << "(2)��ͬ�;��������" << endl;
			cout << "(3)������ˣ�" << endl;
			cout << "(4)���������" << endl;
			cout << "(5)��ͬ�;�����ˣ�" << endl;
			cout << "(6)������ʽ��ֵ��" << endl;
			cout << "(7)�������" << endl;
			cout << "(0)�����������" << endl;
			cout << "(�����κ�ָ��Ϊ�˳���" << endl;
		}
		else {
			cout << "(1)��ͬ�;�����ӣ�" << endl;
			cout << "(2)��ͬ�;��������" << endl;
			cout << "(3)������ˣ�" << endl;
			cout << "(4)���������" << endl;
			cout << "(5)�������ˣ�" << endl;
			cout << "(0)�����������" << endl;
			cout << "(�����κ�ָ��Ϊ�˳���" << endl;
		}
		cout << "���������ָ��:  " << endl;

#pragma endregion

#pragma region ָ������

		while (cin.get()!='\n')
		{
			continue;
		}

		int cmd = -1;
		cin >> cmd;
		if (row == col) {
			MyMatrix mc1{ row,col };
			float n;
			switch (cmd)
			{
			case 1:
				cout << "Ŀǰ�Ĳ���Ϊ�������ӣ�";
				mc1.Create();
				mc += mc1;
				cout << "�õ��Ľ��Ϊ��" << endl;
				mc.Output();
				break;
			case 2:
				cout << "Ŀǰ�Ĳ���Ϊ����������";
				mc1.Create();
				mc -= mc1;
				cout << "�õ��Ľ��Ϊ��" << endl;
				mc.Output();
				break;
			case 3:
				cout << "Ŀǰ�Ĳ���Ϊ������ˣ�������һ������ ";
				cin >> n;
				mc *= n;
				cout << "�õ��Ľ��Ϊ��" << endl;
				mc.Output();
				break;
			case 4:
				cout << "Ŀǰ�Ĳ���Ϊ���������������һ������ ";
				cin >> n;
				mc /= n;
				cout << "�õ��Ľ��Ϊ��" << endl;
				mc.Output();
				break;
			case 5:
				cout << "Ŀǰ�Ĳ���Ϊ�������ˣ�";
				mc1.Create();
				mc *= mc1;
				cout << "�õ��Ľ��Ϊ��" << endl;
				mc.Output();
				break;
			case 6:
				cout << "�þ��������ʽ��ֵΪ��  " << mc.GetDet();
				break;
			case 7:
				cout << "�þ���������Ϊ��";
				mc.Inverse();
				cout << endl;
				mc.Output();
				break;
			case 0:
				break;
			default:
				bQuit = true;
				break;
			}

		}
		else {
			MyMatrix mc1{ row,col };
			MyMatrix mc2;
			float n;
			int c;
			switch (cmd)
			{
			case 1:
				cout << "Ŀǰ�Ĳ���Ϊ�������ӣ�";
				mc1.Create();
				mc += mc1;
				cout << "�õ��Ľ��Ϊ��" << endl;
				mc.Output();
				break;
			case 2:
				cout << "Ŀǰ�Ĳ���Ϊ����������";
				mc1.Create();
				mc -= mc1;
				cout << "�õ��Ľ��Ϊ��" << endl;
				mc.Output();
				break;
			case 3:
				cout << "Ŀǰ�Ĳ���Ϊ������ˣ�������һ������ ";
				cin >> n;
				mc *= n;
				cout << "�õ��Ľ��Ϊ��" << endl;
				mc.Output();
				break;
			case 4:
				cout << "Ŀǰ�Ĳ���Ϊ���������������һ������ ";
				cin >> n;
				mc /= n;
				cout << "�õ��Ľ��Ϊ��" << endl;
				mc.Output();
				break;
			case 5:
				cout << "Ŀǰ�Ĳ���Ϊ�������ˣ�������Ŀ����������:  ";
				cin >> c;
				mc2.Init(col, c);
				mc2.Create();
				mc *= mc2;
				cout << "�õ��Ľ��Ϊ��" << endl;
				mc.Output();
				break;
			case 0:
				break;
			default:
				bQuit = true;
				break;
			}
		}

#pragma endregion

		if (bQuit) {
			break;
		}
	}

#pragma endregion

	return 0;
}

