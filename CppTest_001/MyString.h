#pragma once
class MyString
{
private:

#pragma region 字段

	int arrayLength = 0;
	char* pData;

#pragma endregion

#pragma region 私有方法

	int Strlen(char*);
	int Strlen(MyString&);

#pragma endregion

public:
#pragma region 构造析构函数

	MyString();
	MyString(char*);
	MyString(MyString&);

	~MyString();

#pragma endregion

#pragma region 公有方法

	MyString Strcpy(char*); //复制字符串覆盖此对象
	MyString Strcpy(MyString&);

	//TODO:Strncpy待测试
	MyString Strncpy(char*,int); //复制固定长度字符串覆盖此对象
	MyString Strncpy(MyString&,int);

	int Length(); //字符串长度
	char* ToString(); //字符串输出

	char GetChar(int); //得到字符串中索引字符

	MyString Strcat(char*); //字符串拼接
	MyString Strcat(MyString&);

	MyString Strncat(char*, int); //字符串拼接n个字符
	MyString Strncat(MyString&, int);

	int CompareTo(char*); //字符串比较
	int CompareTo(MyString&);

	MyString Replace(char, char); //字符替换

	MyString Insert(char*, int); //将另一个字符串插入指定索引处
	MyString Insert(MyString&, int);

	MyString SubString(int); //检索给定位置的子字符串
	MyString SubString(int, int);

	//TODO:完善下面方法
	//MyString* Split(char); //在出现给定字符的地方，将字符串拆分为字符串数组
	//MyString ToLower(); //把字符串转换为小写形式
	//MyString ToUpper(); //把字符串转换为大写形式
	//MyString Trim(); //删除首尾空白
	//int IndexOf(char);//取得字符串第一次出现某个给定字符串或字符的位置 
	//int IndexOf(char*); 
	//int IndexOf(MyString&);
	//int* IndexOfAny(char);
	//int* IndexOfAny(char*);
	//int* IndexOfAny(MyString&);
	//MyString Strrev(); //字符串倒序

#pragma endregion

#pragma region 运算符重载

	operator char* () { return pData; } //通过对象名访问数据
	operator const char* () { return pData; }

	char operator[](int index) { return pData[index]; } //索引器
	//char & operator[](int index) const { return pData[index]; }

	MyString& operator+(char*); //重载加法运算符
	MyString& operator+(MyString&);

	MyString& operator+=(char*); //重载加法赋值运算符
	MyString& operator+=(MyString&);

	MyString& operator=(char*); //重载赋值运算符
	MyString& operator=(MyString&);

#pragma endregion

	//TODO:更多的方法
	//TODO:const常量也应适用


};

