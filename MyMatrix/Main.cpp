// Main.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MyMatrix.h"
#include <cmath>
#include <iostream>

int main()
{
	using namespace std;

#pragma region 3*3矩阵运算演示

	cout << "矩阵m1如下：" << endl;
	MyMatrix m1{ 3,3 };
	m1[0][0] = 1;  m1[0][1] = 2;  m1[0][2] = 3;
	m1[1][0] = 4;  m1[1][1] = 5;  m1[1][2] = 6;
	m1[2][0] = 7;  m1[2][1] = 8;  m1[2][2] = 9;
	m1.Output();

	cout << endl << "*****减法*****" << endl;
	cout << "与下面的矩阵m2相减" << endl;
	MyMatrix m2{ 3,3 };
	m2[0][0] = 0;    m2[0][1] = 0;  m2[0][2] = 7;
	m2[1][0] = 6;   m2[1][1] = 3;  m2[1][2] = 5;
	m2[2][0] = 10;  m2[2][1] = 4;  m2[2][2] = 11;
	m2.Output();

	m1 -= m2;
	cout << "得到的新的m1矩阵为：" << endl;
	m1.Output();

	cout << endl << "*****求行列式*****" << endl;
	cout << "m1矩阵的行列式的值为： " << m1.GetDet() << endl;

	cout << endl << "*****乘常数*****" << endl;
	cout << "m1矩阵乘以4得： " << endl;
	m1 *= 4;
	m1.Output();

	cout << endl << "*****除常数*****" << endl;
	cout << "m1矩阵除以2得： " << endl;
	m1 /= 2;
	m1.Output();

	cout << endl << "*****乘矩阵*****" << endl;
	cout << "m1矩阵乘以矩阵m4： " << endl;
	MyMatrix m4{ 3,3 };
	m4[0][0] = 1;  m4[0][1] = 1;  m4[0][2] = 1;
	m4[1][0] = 0;  m4[1][1] = 1;  m4[1][2] = 1;
	m4[2][0] = 0;  m4[2][1] = 0;  m4[2][2] = 1;
	m4.Output();

	m1 *= m4;
	cout << "得到的新的m1矩阵为：" << endl;
	m1.Output();

	cout << endl << "*****加法*****" << endl;
	cout << "与下面的矩阵m3相加：" << endl;
	MyMatrix m3{ 3,3 };
	m3[0][0] = -1;  m3[0][1] = -4;  m3[0][2] = 5;
	m3[1][0] = 6;  m3[1][1] = 2;  m3[1][2] = -1;
	m3[2][0] = 9;  m3[2][1] = 2;  m3[2][2] = 5;
	m3.Output();

	m1 += m3;
	cout << "得到的新的m1矩阵为：" << endl;
	m1.Output();

	cout << endl << "*****求逆矩阵*****" << endl;
	m1.Inverse();
	cout << "矩阵m1求逆后的矩阵如下：" << endl;
	m1.Output();

	cout << endl << endl << "上面部分为m*n矩阵类中的3*3矩阵演示运算" << endl;
	cout << "**************************************" << endl;

#pragma endregion

#pragma region m*n矩阵运算系统

	cout << endl << "**************************************" << endl;
	cout << "*********  m*n矩阵运算系统  **********" << endl;
	cout << "**************************************" << endl << endl;

	while (true) {
		bool bQuit = false; 

		cout << "创建m*n矩阵，请分别输入行数和列数：" << endl;
		int row, col;
		cin >> row >> col;
		MyMatrix mc{ row,col };
		mc.Create();
		cout << endl << "**************************************" << endl;
		cout << "你输入的" << row << "*" << col << "矩阵的情况如下：" << endl;
		mc.Output();
		cout << "**************************************" << endl;
		cout << "请选择你要进行的操作：" << endl;

#pragma region 菜单显示

		//只有n阶矩阵可求行列式和求逆
		if (row == col) {
			cout << "(1)与同型矩阵相加；" << endl;
			cout << "(2)与同型矩阵相减；" << endl;
			cout << "(3)与数相乘；" << endl;
			cout << "(4)与数相除；" << endl;
			cout << "(5)与同型矩阵相乘；" << endl;
			cout << "(6)求行列式的值；" << endl;
			cout << "(7)求逆矩阵；" << endl;
			cout << "(0)重新输入矩阵；" << endl;
			cout << "(其它任何指令为退出）" << endl;
		}
		else {
			cout << "(1)与同型矩阵相加；" << endl;
			cout << "(2)与同型矩阵相减；" << endl;
			cout << "(3)与数相乘；" << endl;
			cout << "(4)与数相除；" << endl;
			cout << "(5)与矩阵相乘；" << endl;
			cout << "(0)重新输入矩阵；" << endl;
			cout << "(其它任何指令为退出）" << endl;
		}
		cout << "请输入你的指令:  " << endl;

#pragma endregion

#pragma region 指令运算

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
				cout << "目前的操作为与矩阵相加，";
				mc1.Create();
				mc += mc1;
				cout << "得到的结果为：" << endl;
				mc.Output();
				break;
			case 2:
				cout << "目前的操作为与矩阵相减，";
				mc1.Create();
				mc -= mc1;
				cout << "得到的结果为：" << endl;
				mc.Output();
				break;
			case 3:
				cout << "目前的操作为与数相乘，请输入一个数： ";
				cin >> n;
				mc *= n;
				cout << "得到的结果为：" << endl;
				mc.Output();
				break;
			case 4:
				cout << "目前的操作为与数相除，请输入一个数： ";
				cin >> n;
				mc /= n;
				cout << "得到的结果为：" << endl;
				mc.Output();
				break;
			case 5:
				cout << "目前的操作为与矩阵相乘，";
				mc1.Create();
				mc *= mc1;
				cout << "得到的结果为：" << endl;
				mc.Output();
				break;
			case 6:
				cout << "该矩阵的行列式的值为：  " << mc.GetDet();
				break;
			case 7:
				cout << "该矩阵的逆矩阵为：";
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
				cout << "目前的操作为与矩阵相加，";
				mc1.Create();
				mc += mc1;
				cout << "得到的结果为：" << endl;
				mc.Output();
				break;
			case 2:
				cout << "目前的操作为与矩阵相减，";
				mc1.Create();
				mc -= mc1;
				cout << "得到的结果为：" << endl;
				mc.Output();
				break;
			case 3:
				cout << "目前的操作为与数相乘，请输入一个数： ";
				cin >> n;
				mc *= n;
				cout << "得到的结果为：" << endl;
				mc.Output();
				break;
			case 4:
				cout << "目前的操作为与数相除，请输入一个数： ";
				cin >> n;
				mc /= n;
				cout << "得到的结果为：" << endl;
				mc.Output();
				break;
			case 5:
				cout << "目前的操作为与矩阵相乘，请输入目标矩阵的列数:  ";
				cin >> c;
				mc2.Init(col, c);
				mc2.Create();
				mc *= mc2;
				cout << "得到的结果为：" << endl;
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

