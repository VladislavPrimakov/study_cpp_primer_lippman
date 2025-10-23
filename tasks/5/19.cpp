//Упражнение 5.19.Напишите программу, использующую цикл do while
//для циклического запроса у пользователя двух строк и указания, которая из
//них меньше другой.

#include <iostream>
#include <string>
using namespace std;

int main() {
	string rsp;
	do {
		string str1, str2;
		cout << "Enter first string: ";
		getline(cin, str1);
		cout << "Enter second string: ";
		getline(cin, str2);
		if (str1 < str2)
			cout << "\"" << str1 << "\" is less than \"" << str2 << "\"" << endl;
		else if (str1 > str2)
			cout << "\"" << str1 << "\" is greater than \"" << str2 << "\"" << endl;
		else
			cout << "The strings are equal." << endl;
		cout << "Enter n or nothing to exit: ";
		getline(cin, rsp);
	} while (rsp.size() && rsp[0] == 'y');
	return 0;
}