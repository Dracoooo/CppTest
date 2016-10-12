#pragma once
class MyString
{
private:

#pragma region �ֶ�

	int arrayLength = 0;
	char* pData;

#pragma endregion

#pragma region ˽�з���

	int Strlen(char*);
	int Strlen(MyString&);

#pragma endregion

public:
#pragma region ������������

	MyString();
	MyString(char*);
	MyString(MyString&);

	~MyString();

#pragma endregion

#pragma region ���з���

	MyString Strcpy(char*); //�����ַ������Ǵ˶���
	MyString Strcpy(MyString&);

	//TODO:Strncpy������
	MyString Strncpy(char*,int); //���ƹ̶������ַ������Ǵ˶���
	MyString Strncpy(MyString&,int);

	int Length(); //�ַ�������
	char* ToString(); //�ַ������

	char GetChar(int); //�õ��ַ����������ַ�

	MyString Strcat(char*); //�ַ���ƴ��
	MyString Strcat(MyString&);

	MyString Strncat(char*, int); //�ַ���ƴ��n���ַ�
	MyString Strncat(MyString&, int);

	int CompareTo(char*); //�ַ����Ƚ�
	int CompareTo(MyString&);

	MyString Replace(char, char); //�ַ��滻

	MyString Insert(char*, int); //����һ���ַ�������ָ��������
	MyString Insert(MyString&, int);

	MyString SubString(int); //��������λ�õ����ַ���
	MyString SubString(int, int);

	//TODO:�������淽��
	//MyString* Split(char); //�ڳ��ָ����ַ��ĵط������ַ������Ϊ�ַ�������
	//MyString ToLower(); //���ַ���ת��ΪСд��ʽ
	//MyString ToUpper(); //���ַ���ת��Ϊ��д��ʽ
	//MyString Trim(); //ɾ����β�հ�
	//int IndexOf(char);//ȡ���ַ�����һ�γ���ĳ�������ַ������ַ���λ�� 
	//int IndexOf(char*); 
	//int IndexOf(MyString&);
	//int* IndexOfAny(char);
	//int* IndexOfAny(char*);
	//int* IndexOfAny(MyString&);
	//MyString Strrev(); //�ַ�������

#pragma endregion

#pragma region ���������

	operator char* () { return pData; } //ͨ����������������
	operator const char* () { return pData; }

	char operator[](int index) { return pData[index]; } //������
	//char & operator[](int index) const { return pData[index]; }

	MyString& operator+(char*); //���ؼӷ������
	MyString& operator+(MyString&);

	MyString& operator+=(char*); //���ؼӷ���ֵ�����
	MyString& operator+=(MyString&);

	MyString& operator=(char*); //���ظ�ֵ�����
	MyString& operator=(MyString&);

#pragma endregion

	//TODO:����ķ���
	//TODO:const����ҲӦ����


};

