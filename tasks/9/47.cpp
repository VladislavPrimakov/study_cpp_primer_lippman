//Упражнение 9.47.Напишите программу, которая находит в строке
//Mab2c3d7R4E6" каждую цифру, а затем каждую букву. Напишите две 
//версии программы : с использованием функции find_firstof() и функции
//find_first_not_of().

#include <iostream>
#include <string>
using namespace std;

int main() {
	string s = "Mab2c3d7R4E6";
	size_t index = 0;
	cout << "Using find_first_of(): ";
	while ((index = s.find_first_of("0123456789", index)) != string::npos) {
		cout << s[index] << " ";
		++index;
	}
	cout << endl;
	index = 0;
	cout << "Using find_first_not_of(): ";
	while ((index = s.find_first_not_of("0123456789", index)) != string::npos) {
		cout << s[index] << " ";
		++index;
	}
	cout << endl;
	return 0;
}