//Упражнение 3.7.Что будет, если определить управляющую переменную
//цикла в предыдущем упражнении как имеющую тип char ? Предскажите
//результат, а затем измените программу так, чтобы использовался тип char,
//и убедитесь в своей правоте.

#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cout << "Enter a string:\n";
	getline(cin, s);
	for (char& ch : s) {
		ch = 'x';
	}
	cout << "Modified string:\n" << s << endl;
	return 0;
}