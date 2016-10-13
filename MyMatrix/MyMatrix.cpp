#include "stdafx.h"
#include "MyMatrix.h"
#include <cmath>
#include <iostream>

MyMatrix::MyMatrix() {}

MyMatrix::MyMatrix(int r, int c) {
	m_row = r;
	m_col = c;

	m_pData = new float*[m_row];
	for (int i = 0; i < m_row; i++) {
		m_pData[i] = new float[m_col];
		for (int j = 0; j < m_col; j++) {
			m_pData[i][j] = 0;
		}
	}
}

MyMatrix::~MyMatrix() {
	for (int i = 0; i < m_row; i++) {
		delete[] m_pData[i];
	}
	delete[] m_pData;
}

void MyMatrix::Init(int r, int c) {
	m_row = r;
	m_col = c;

	m_pData = new float*[m_row];
	for (int i = 0; i < m_row; i++) {
		m_pData[i] = new float[m_col];
		for (int j = 0; j < m_col; j++) {
			m_pData[i][j] = 0;
		}
	}
}

void MyMatrix::Create() {
	std::cout << "请输入一个" << m_row << "*" << m_col << "矩阵的值" << std::endl;
	for (int i = 0; i < m_row; i++) {
		for (int j = 0; j < m_col; j++) {
			//对错误的输入进行忽略
			if (!(std::cin >> m_pData[i][j]))
			{
				std::cin.clear();
				while (std::cin.get() != '\n') {
					continue;
				}
				j--;
			}

		}
	}

	std::cout << "赋值成功" << std::endl;
}

void MyMatrix::Output() {
	for (int i = 0; i < m_row; i++) {
		for (int j = 0; j < m_col; j++) {
			//TODO: float类型的只区分0和-0
			if (fabs(m_pData[i][j]) < 0.001) {
				m_pData[i][j] = 0;
			}
			std::cout << m_pData[i][j] << '\t';
		}
		std::cout << std::endl;
	}
}

void MyMatrix::Sum(const MyMatrix& other) {
	if (m_row != other.m_row || m_col != other.m_col) {
		std::cout << "警告：矩阵相加操作没有成功，因为不是同型矩阵" << std::endl;
		return;
	}
	for (int i = 0; i < m_row; i++) {
		for (int j = 0; j < m_col; j++) {
			m_pData[i][j] += other[i][j];
		}
	}
}

void MyMatrix::Minus(const MyMatrix& other) {
	if (m_row != other.m_row || m_col != other.m_col) {
		std::cout << "警告：矩阵相减操作没有成功，因为不是同型矩阵" << std::endl;
		return;
	}
	for (int i = 0; i < m_row; i++) {
		for (int j = 0; j < m_col; j++) {
			m_pData[i][j] -= other[i][j];
		}
	}
}

void MyMatrix::Multiply(float n) {
	for (int i = 0; i < m_row; i++) {
		for (int j = 0; j < m_col; j++) {
			m_pData[i][j] *= n;
		}
	}
}

void MyMatrix::Multiply(const MyMatrix& other) {
	if (m_col != other.m_row) {
		std::cout << "警告：矩阵相乘操作没有成功，因为列不等于行" << std::endl;
		return;
	}

	float** preData = m_pData;
	int preCol = m_col;
	m_col = other.m_col;

	m_pData = new float*[m_row];
	for (int i = 0; i < m_row; i++) {
		m_pData[i] = new float[m_col];
		for (int j = 0; j < m_col; j++) {
			m_pData[i][j] = 0;
		}
	}

	float total = 0;
	for (int r = 0; r < m_row; r++) {
		for (int o_c = 0; o_c < other.m_col; o_c++) {
			for (int c = 0; c < preCol; c++) {
				total += preData[r][c] * other[c][o_c];
			}
			m_pData[r][o_c] = total;
			total = 0;
		}
	}

	for (int i = 0; i < m_row; i++) {
		delete[] preData[i];
	}
	delete[] preData;
}

void MyMatrix::Divide(float n) {
	for (int i = 0; i < m_row; i++) {
		for (int j = 0; j < m_col; j++) {
			m_pData[i][j] /= n;
		}
	}
}

float MyMatrix::GetElement(int r, int c) {
	return m_pData[r - 1][c - 1];
}

float MyMatrix::GetDet() {
	if (m_row != m_col) {
		std::cout << "错误，该矩阵无法求行列式" << std::endl;
		//TODO:不满足条件的时候不想返回任何值
		return 0;
	}
	return Det(*this);
}

float MyMatrix::Det(const MyMatrix& other) {
	if (other.m_row != other.m_col) {
		std::cout << "错误，该矩阵无法求行列式" << std::endl;
		//TODO:不满足条件的时候不想返回任何值
		return 0;
	}

	float total = 0;
	//if (other.m_col > 3) {
	if (other.m_col > 2) {
		for (int j = 0; j < other.m_col; j++) {
			//TODO：Cofactor求余子式的与行列式的耦合性太高
			MyMatrix temp{ other.m_row - 1,other.m_col - 1 };
			Cofactor(other, 1, j + 1, temp);
			total += other[0][j] * (int)pow(-1, 1 + j + 1) *Det(temp);
		}
		return total;
	}
	else
	{
		//3阶行列式对角线法则计算
		//return other[0][0] * other[1][1] * other[2][2] + other[0][1] * other[1][2] * other[2][0] + other[0][2] * other[1][0] * other[2][1] - other[0][2] * other[1][1] * other[2][0] - other[0][1] * other[1][0] * other[2][2] - other[0][0] * other[1][2] * other[2][1];
		return other[0][0] * other[1][1] - other[0][1] * other[1][0];
	}
}

void MyMatrix::Cofactor(const MyMatrix& other, int other_i, int other_j, MyMatrix& save) {
	MyMatrix pM{ other.m_row - 1,other.m_col - 1 };
	for (int i = 0; i < pM.m_row; i++) {
		if (i < other_i - 1) {
			for (int j = 0; j < pM.m_col; j++) {
				if (j < other_j - 1) {
					pM[i][j] = other[i][j];
				}
				else
				{
					pM[i][j] = other[i][j + 1];
				}
			}
		}
		else
		{
			for (int j = 0; j < pM.m_col; j++) {
				if (j < other_j - 1) {
					pM[i][j] = other[i + 1][j];
				}
				else
				{
					pM[i][j] = other[i + 1][j + 1];
				}
			}
		}
	}

	//TODO:局部指针变量代替方案 （怎么返回堆空间）
	//TODO:目前采用传参数来接收...
	//return pM;
	save = pM;
}

void MyMatrix::Inverse() {
	float det = GetDet();

	if (fabs(det) < 0.001) {
		std::cout << "奇异矩阵无法求逆" << std::endl;
		return;
	}

	MyMatrix Adjugate{ m_row,m_col };

	for (int i = 0; i < Adjugate.m_row; i++) {
		for (int j = 0; j < Adjugate.m_col; j++) {
			//TODO：Cofactor求余子式的与行列式的耦合性太高
			MyMatrix temp{ m_row - 1,m_col - 1 };
			Cofactor(*this, j + 1, i + 1, temp);
			Adjugate[i][j] = (int)pow(-1, i + j) * Det(temp);
		}
	}

	Adjugate /= det;

	*this = Adjugate;
	//return Adjugate;
	//TODO:不能返回局部指针变量，只能改变矩阵本身的值了
}

#pragma region 运算符重载

MyMatrix& MyMatrix::operator=(const MyMatrix& other) {
	if (m_row != other.m_row || m_col != other.m_col) {
		std::cout << "非同型矩阵不能赋值" << std::endl;
		return *this;
	}

	//	for (int i = 0; i < m_row; i++) {
	//		delete[] m_pData[i];
	//	}
	//	delete[] m_pData;

	//	m_pData = new int*[m_row];
	//	for (int i = 0; i < m_row; i++) {
	//		m_pData[i] = new int[m_col];
	//		for (int j = 0; j < m_col; j++) {
	//			m_pData[i][j] = 0;
	//		}
	//	}

	for (int i = 0; i < m_row; i++) {
		for (int j = 0; j < m_col; j++) {
			m_pData[i][j] = other[i][j];
		}
	}

	return *this;
}

MyMatrix& MyMatrix::operator+(const MyMatrix& other) {
	Sum(other);
	return *this;
}

MyMatrix& MyMatrix::operator+=(const MyMatrix& other) {
	Sum(other);
	return *this;
}

MyMatrix& MyMatrix::operator-(const MyMatrix& other) {
	Minus(other);
	return *this;
}

MyMatrix& MyMatrix::operator-=(const MyMatrix& other) {
	Minus(other);
	return *this;
}

MyMatrix& MyMatrix::operator*(const MyMatrix& other) {
	Multiply(other);
	return *this;
}

MyMatrix& MyMatrix::operator*=(const MyMatrix& other) {
	Multiply(other);
	return *this;
}

MyMatrix& MyMatrix::operator*(float n) {
	Multiply(n);
	return *this;
}

MyMatrix& MyMatrix::operator*=(float n) {
	Multiply(n);
	return *this;
}

MyMatrix& MyMatrix::operator/(float n) {
	Divide(n);
	return *this;
}

MyMatrix& MyMatrix::operator/=(float n) {
	Divide(n);
	return *this;
}

#pragma endregion

