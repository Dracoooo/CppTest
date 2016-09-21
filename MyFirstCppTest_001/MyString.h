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

	MyString Strcpy(char *); //�����ַ������Ǵ˶���
	MyString Strcpy(MyString&);

	int Length(); //�ַ�������
	char * ToString(); //�ַ������

	char GetChar(int); //�õ��ַ����������ַ�

	MyString Strcat(char *); //�ַ���ƴ��
	MyString Strcat(MyString&); 

	MyString Strncat(char *, int); //�ַ���ƴ��n���ַ�
	MyString Strncat(MyString&, int);

	int CompareTo(char *); //�ַ����Ƚ�
	int CompareTo(MyString&); 

	MyString Replace(char, char); //�ַ��滻

	MyString Insert(char *, int); //����һ���ַ�������ָ��������
	MyString Insert(MyString&, int); 

	MyString SubString(int); //��������λ�õ����ַ���
	MyString SubString(int, int);



	operator const char * () { return pData; } //ͨ����������������

	char operator[](int index) { return pData[index]; } //������
	char & operator[](int index) const { return pData[index]; }

	MyString& operator+(char *); //���ؼӷ������
	MyString& operator+(MyString&);

	MyString& operator+=(char *); //���ؼӷ���ֵ�����
	MyString& operator+=(MyString&);

	MyString& operator=(char *); //���ظ�ֵ�����
	MyString& operator=(MyString&);


};

