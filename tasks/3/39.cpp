//Упражнение 3.39.Напишите программу, сравнивающую две строки.Затем
//напишите программу, сравнивающую значения двух символьных строк
//в стиле С.

#include <iostream>
using namespace std;

int main() {
	const size_t size = 100;
	char str1[size];
	char str2[size];
	cout << "Enter first string: ";
	cin.getline(str1, size);
	cout << "Enter second string: ";
	cin.getline(str2, size);
	char* p1 = str1;
	char* p2 = str2;
	bool areEqual = true;
	while (*p1 != '\0' && *p2 != '\0') {
		if (*p1 != *p2) {
			areEqual = false;
			break;
		}
		++p1;
		++p2;
	}
	if (*p1 != *p2) {
		areEqual = false;
	}
	if (areEqual) {
		cout << "Strings are equal." << endl;
	} else {
		cout << "Strings are not equal." << endl;
	}
	return 0;
}