//Упражнение 12.23.Напишите программу, конкатенирующую два
//строковых литерала и помещающую результат в динамически созданный массив
//символов.Напишите программу, конкатенирующую две строки
//библиотечного типа string, имеющих те же значения, что и строковые литералы,
//используемые в первой программе.


#include <iostream>
#include <string>
using namespace std;

int main() {
	string str1 = "Hello, ";
	string str2 = "World!";
	size_t bufferSize = str1.size() + str2.size() + 1;
	char* cstr = new char[bufferSize];
	strcpy_s(cstr, bufferSize, str1.c_str());
	strcat_s(cstr, bufferSize, str2.c_str());
	for (char* p = cstr; *p != '\0'; ++p) {
		cout << *p;
	}
	return 0;
}