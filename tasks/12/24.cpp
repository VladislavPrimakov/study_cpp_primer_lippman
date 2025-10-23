//Упражнение 12.24.Напишите программу, которая читает строку со
//стандартного устройства ввода в динамически созданный символьный массив.
//Объясните, как программа обеспечивает ввод данных переменного размера.
//Проверьте свою программу, введя строку, размер которой превышает
//длину зарезервированного массива.


#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	char* buffer = new char[10];
	int i = 0, c;
	cout << "Enter a string (end with EOF): ";
	while ((c = getchar()) != EOF) {
		buffer[i++] = c;
	}
	buffer[i] = '\0';
	cout << "You entered: ";
	for (int j = 0; j < i; ++j) {
		cout << buffer[j];
	}

	delete[] buffer;
	return 0;
}