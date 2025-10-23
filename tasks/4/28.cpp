//Упражнение 4.28.Напишите программу для вывода размера каждого из
//встроенных типов.

#include <iostream>
using namespace std;

int main() {
	cout << "Size of char: " << sizeof(char) << " byte(s)" << endl;
	cout << "Size of wchar_t: " << sizeof(wchar_t) << " byte(s)" << endl;
	cout << "Size of char16_t: " << sizeof(char16_t) << " byte(s)" << endl;
	cout << "Size of char32_t: " << sizeof(char32_t) << " byte(s)" << endl;
	cout << "Size of short: " << sizeof(short) << " byte(s)" << endl;
	cout << "Size of int: " << sizeof(int) << " byte(s)" << endl;
	cout << "Size of long: " << sizeof(long) << " byte(s)" << endl;
	cout << "Size of long long: " << sizeof(long long) << " byte(s)" << endl;
	cout << "Size of float: " << sizeof(float) << " byte(s)" << endl;
	cout << "Size of double: " << sizeof(double) << " byte(s)" << endl;
	cout << "Size of long double: " << sizeof(long double) << " byte(s)" << endl;
	void* v;
	cout << "Size of *void: " << sizeof(v) << " byte(s)" << endl;
	cout << "Size of bool: " << sizeof(bool) << " byte(s)" << endl;
	return 0;
}