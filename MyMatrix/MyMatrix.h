
#pragma once



class MyMatrix
{
public:
	MyMatrix(int r, int c);
	~MyMatrix();

	void Create(); //��������һ������
	void Output(); //�����ʾһ������

	void Sum(const MyMatrix&); //�������

	void Minus(const MyMatrix&); //�������

	void Multiply(float); //����˳���

	void Multiply(const MyMatrix&); //����˾���

	void Divide(float); //���������

	float GetElement(int row, int col); //�õ�����Ԫ

	float GetDet(); //�õ�����ʽ��ֵ

	void Inverse(); //����

	//TODO:����ĵ���

#pragma region ���������

	//operator int** () { return m_pData; } //ͨ����������������
	operator float**  const () { return m_pData; } //ͨ����������������

	float* operator[](int index) { return m_pData[index]; } //������
	float* operator[](int index)const { return m_pData[index]; } //������

	MyMatrix& operator=(const MyMatrix&);
	MyMatrix& operator+(const MyMatrix&);
	MyMatrix& operator+=(const MyMatrix&);
	MyMatrix& operator-(const MyMatrix&);
	MyMatrix& operator-=(const MyMatrix&);
	MyMatrix& operator*(const MyMatrix&);
	MyMatrix& operator*=(const MyMatrix&);
	MyMatrix& operator*(float);
	MyMatrix& operator*=(float);
	MyMatrix& operator/(float);
	MyMatrix& operator/=(float);

#pragma endregion


private:
	int m_row;
	int m_col;

	float** m_pData;

	float Det(const MyMatrix&);
	//MyMatrix& Cofactor(const MyMatrix&, int, int);
	void Cofactor(const MyMatrix&, int, int, MyMatrix&);
};



//TODO:ʵ�ֳ�������Ҳ����
//TODO��������ֵ����const����ֹ���޸�
//TODO: ��������ֵΪ���󣬶�����void���������޸�
//TODO: ��֤�������ȷ�ԣ�float����int����