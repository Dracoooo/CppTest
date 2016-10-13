
#pragma once



class MyMatrix
{
public:
	MyMatrix();
	MyMatrix(int r, int c);
	~MyMatrix();

	int GetRow() { return m_row; }
	int GetCol() { return m_col; }
	
	void Init(int r,int c); //允许声明矩阵之后再定义矩阵的行数列数

	void Create(); //创建输入一个矩阵
	void Output(); //输出显示一个矩阵

	void Sum(const MyMatrix&); //矩阵相加

	void Minus(const MyMatrix&); //矩阵相减

	void Multiply(float); //矩阵乘常数

	void Multiply(const MyMatrix&); //矩阵乘矩阵

	void Divide(float); //矩阵除常数

	float GetElement(int row, int col); //得到矩阵元

	float GetDet(); //得到行列式的值

	void Inverse(); //求逆

	//TODO:矩阵的倒置

#pragma region 运算符重载

	//operator int** () { return m_pData; } //通过对象名访问数据
	operator float**  const () { return m_pData; } //通过对象名访问数据

	float* operator[](int index) { return m_pData[index]; } //索引器
	float* operator[](int index)const { return m_pData[index]; } //索引器

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
	//TODO: 实现可以转换计算，比如现在矩阵*常量可以，但是常量*矩阵就不可以了（友元是什么）


#pragma endregion


private:
	int m_row;
	int m_col;

	float** m_pData;

	float Det(const MyMatrix&);
	//MyMatrix& Cofactor(const MyMatrix&, int, int);
	void Cofactor(const MyMatrix&, int, int, MyMatrix&);
};



//TODO:实现常量矩阵也适用
//TODO：函数传值采用const，防止被修改
//TODO: 函数返回值为矩阵，而不是void这样方便修改
//TODO: 验证输入的正确性，float数？int数？ 警报提示?(目前采取忽略措施)
