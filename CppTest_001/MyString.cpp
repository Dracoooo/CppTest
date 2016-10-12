#include "stdafx.h"
#include "MyString.h"

MyString::MyString() {

}

MyString::MyString(char* str)
{

	arrayLength = Strlen(str);

	pData = new char[arrayLength + 1];

	for (int i = 0; i < arrayLength; i++)
	{
		pData[i] = str[i];
	}

	pData[arrayLength] = '\0';
}

MyString::MyString(MyString& strClass)
{

	arrayLength = strClass.Length();

	pData = new char[arrayLength + 1];

	for (int i = 0; i < arrayLength; i++)
	{
		pData[i] = strClass[i];
	}

	pData[arrayLength] = '\0';
}

MyString::~MyString()
{
	//delete pData;
	delete [] pData;
}

int MyString::Strlen(char* str) {
	int length = 0;
	for (int i = 0;; i++) {
		if (str[i] == '\0') {
			break;
		}
		else {
			length++;
		}
	}
	return length;
}

int MyString::Strlen(MyString& strClass) {
	int length = 0;
	for (int i = 0;; i++) {
		if (strClass[i] == '\0') {
			break;
		}
		else {
			length++;
		}
	}
	return length;
}

MyString MyString::Strcpy(char* str) {
	arrayLength = Strlen(str);

	if (pData != NULL) {
		delete [] pData; //删除旧数据
	}

	pData = new char[arrayLength + 1];

	for (int i = 0; i < arrayLength; i++)
	{
		pData[i] = str[i];
	}

	pData[arrayLength] = '\0';
	return *this;
}

MyString MyString::Strcpy(MyString& strClass) {
	if (this == &strClass) {
		return *this;
	}

	arrayLength = strClass.Length();

	if (pData != NULL) {
		delete [] pData; //删除旧数据
	}

	pData = new char[arrayLength + 1];

	for (int i = 0; i < arrayLength; i++)
	{
		pData[i] = strClass[i];
	}

	pData[arrayLength] = '\0';
	return *this;
}

MyString MyString::Strncpy(char* str, int n) {
	if (n >= Strlen(str)) {
		Strcpy(str);
	}
	else
	{
		arrayLength = n;
	}

	if (pData != NULL) {
		delete [] pData; //删除旧数据
	}

	pData = new char[arrayLength + 1];

	for (int i = 0; i < arrayLength; i++)
	{
		pData[i] = str[i];
	}

	pData[arrayLength] = '\0';
	return *this;
}

MyString MyString::Strncpy(MyString& strClass,int n) {
	if (n >= strClass.Length()) {
		Strcpy(strClass);
	}
	else
	{
		arrayLength = n;
	}

	if (pData != NULL) {
		delete [] pData; //删除旧数据
	}

	pData = new char[arrayLength + 1];

	for (int i = 0; i < arrayLength; i++)
	{
		pData[i] = strClass[i];
	}

	pData[arrayLength] = '\0';
	return *this;
}

int MyString::Length() {
	return arrayLength;
}

char* MyString::ToString() {
	return pData;
}

char MyString::GetChar(int index) {
	return pData[index];
}

MyString MyString::Strcat(char* str) {
	int strLength = Strlen(str);

	int preLength = arrayLength;
	arrayLength += strLength;

	char* pPreData = pData;
	pData = new char[arrayLength + 1];

	for (int i = 0; i < preLength; i++) {
		pData[i] = pPreData[i];
	}
	for (int i = preLength; i < arrayLength; i++) {
		pData[i] = str[i - preLength];
	}

	pData[arrayLength] = '\0';

	delete [] pPreData;
	return *this;
}

MyString MyString::Strcat(MyString& strClass) {
	int strLength = Strlen(strClass);

	int preLength = arrayLength;
	arrayLength += strLength;

	char* pPreData = pData;
	pData = new char[arrayLength + 1];

	for (int i = 0; i < preLength; i++) {
		pData[i] = pPreData[i];
	}
	for (int i = preLength; i < arrayLength; i++) {
		pData[i] = strClass[i - preLength];
	}

	pData[arrayLength] = '\0';

	delete [] pPreData;
	return *this;
}

MyString MyString::Strncat(char* str, int n) {
	int preLength = arrayLength;
	arrayLength += n;

	char* pPreData = pData;
	pData = new char[arrayLength + 1];

	for (int i = 0; i < preLength; i++) {
		pData[i] = pPreData[i];
	}
	for (int i = preLength; i < arrayLength; i++) {
		pData[i] = str[i - preLength];
	}

	pData[arrayLength] = '\0';

	delete [] pPreData;
	return *this;
}

MyString MyString::Strncat(MyString& strClass, int n) {
	int preLength = arrayLength;
	arrayLength += n;

	char* pPreData = pData;
	pData = new char[arrayLength + 1];

	for (int i = 0; i < preLength; i++) {
		pData[i] = pPreData[i];
	}
	for (int i = preLength; i < arrayLength; i++) {
		pData[i] = strClass[i - preLength];
	}

	pData[arrayLength] = '\0';

	delete [] pPreData;
	return *this;
}

int MyString::CompareTo(char* str) {
	int strLength = Strlen(str);

	int c_Length = arrayLength < strLength ? arrayLength : strLength;

	int index = -1;
	for (int i = 0; i < c_Length; i++) {
		if (pData[i] != str[i]) {
			index = i;
			break;
		}
	}

	if (index != -1) {
		if (pData[index] > str[index]) {
			return 1;
		}
		else {
			return -1;
		}
	}
	else {
		if (arrayLength == strLength) {
			return 0;
		}
		else {
			if (arrayLength > strLength) {
				return 1;
			}
			else {
				return -1;
			}
		}
	}
}

int MyString::CompareTo(MyString& strClass) {
	int strLength = Strlen(strClass);

	int c_Length = arrayLength < strLength ? arrayLength : strLength;

	int index = -1;
	for (int i = 0; i < c_Length; i++) {
		if (pData[i] != strClass[i]) {
			index = i;
			break;
		}
	}

	if (index != -1) {
		if (pData[index] > strClass[index]) {
			return 1;
		}
		else {
			return -1;
		}
	}
	else {
		if (arrayLength == strLength) {
			return 0;
		}
		else {
			if (arrayLength > strLength) {
				return 1;
			}
			else {
				return -1;
			}
		}
	}
}

MyString MyString::Replace(char a, char b) {
	for (int i = 0; i < arrayLength; i++) {
		if (pData[i] == a) {
			pData[i] = b;
		}
	}
	return *this;
}

MyString MyString::Insert(char* str, int index) {
	int strLength = Strlen(str);

	arrayLength += strLength;

	char* pPreData = pData;
	pData = new char[arrayLength + 1];

	for (int i = 0; i < arrayLength; i++) {
		if (i < index) {
			pData[i] = pPreData[i];
		}
		else if (i >= index && i < index + strLength) {
			pData[i] = str[i - index];
		}
		else {
			pData[i] = pPreData[i - strLength];
		}
	}

	pData[arrayLength] = '\0';

	delete [] pPreData;
	return *this;
}

MyString MyString::Insert(MyString& strClass, int index) {
	int strLength = Strlen(strClass);

	arrayLength += strLength;

	char* pPreData = pData;
	pData = new char[arrayLength + 1];

	for (int i = 0; i < arrayLength; i++) {
		if (i < index) {
			pData[i] = pPreData[i];
		}
		else if (i >= index && i < index + strLength) {
			pData[i] = strClass[i - index];
		}
		else {
			pData[i] = pPreData[i - strLength];
		}
	}

	pData[arrayLength] = '\0';

	delete [] pPreData;
	return *this;
}

MyString MyString::SubString(int index) {
	if (index < arrayLength) {
		arrayLength -= index;
	}
	else {
		return pData;
	}

	char* pPreData = pData;
	pData = new char[arrayLength + 1];

	for (int i = 0; i < arrayLength; i++) {
		pData[i] = pPreData[i + index];
	}

	pData[arrayLength] = '\0';

	delete [] pPreData;
	return *this;
}

MyString MyString::SubString(int index0, int index1) {
	if (index1 < arrayLength) {
		arrayLength = (index1 + 1) - index0;
	}
	else {
		return pData;
	}

	char* pPreData = pData;
	pData = new char[arrayLength + 1];

	for (int i = 0; i < arrayLength; i++) {
		pData[i] = pPreData[i + index0];
	}

	pData[arrayLength] = '\0';

	delete [] pPreData;
	return *this;
}

MyString& MyString::operator+(char* str) {
	Strcat(str);
	return *this;
}

MyString& MyString::operator+(MyString& strClass) {
	Strcat(strClass);
	return *this;
}

MyString& MyString::operator+=(char* str) {
	Strcat(str);
	return *this;
}

MyString& MyString::operator+=(MyString& strClass) {
	Strcat(strClass);
	return *this;
}

MyString& MyString::operator=(char* str) {
	Strcpy(str);
	return *this;
}

MyString& MyString::operator=(MyString& strClass) {
	Strcpy(strClass);
	return *this;
}

