#pragma once
class MyString
{
	int arrayLength = 0;
	char * pData;

	int Strlen(char *);
	int Strlen(MyString&);

public:
	MyString(char *);
	MyString(MyString&);

	~MyString();

	MyString Strcpy(char *); //复制字符串覆盖此对象
	MyString Strcpy(MyString&);

	int Length(); //字符串长度
	char * ToString(); //字符串输出

	char GetChar(int); //得到字符串中索引字符

	MyString Strcat(char *); //字符串拼接
	MyString Strcat(MyString&); 

	MyString Strncat(char *, int); //字符串拼接n个字符
	MyString Strncat(MyString&, int);

	int CompareTo(char *); //字符串比较
	int CompareTo(MyString&); 

	MyString Replace(char, char); //字符替换

	MyString Insert(char *, int); //将另一个字符串插入指定索引处
	MyString Insert(MyString&, int); 

	MyString SubString(int); //检索给定位置的子字符串
	MyString SubString(int, int);



	operator const char * () { return pData; } //通过对象名访问数据

	char operator[](int index) { return pData[index]; } //索引器
	char & operator[](int index) const { return pData[index]; }

	MyString& operator+(char *); //重载加法运算符
	MyString& operator+(MyString&);

	MyString& operator+=(char *); //重载加法赋值运算符
	MyString& operator+=(MyString&);

	MyString& operator=(char *); //重载赋值运算符
	MyString& operator=(MyString&);


};

