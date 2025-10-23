//Упражнение 3.2.Напишите программу, читающую со стандартного
//устройства ввода по одной строке за раз.Измените программу так, чтобы
//читать по одному слову за раз.

#include <iostream>
#include <string>

using namespace std;

int main() {
	string word;
	while (cin >> word)
		cout << word << std::endl;
	return 0;
}