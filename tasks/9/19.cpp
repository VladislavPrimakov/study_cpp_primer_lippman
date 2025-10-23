//Упражнение 9.19.Перепишите программу из предыдущего упражнения,
//чтобы использовался контейнер list.Перечислите необходимые изменения.

#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
	list<string> str_list;
	string s;
	cout << "Enter strings (CTRL+Z to end):" << endl;
	while (getline(cin, s)) {
		str_list.insert(str_list.cbegin(), s);
	}
	cout << "You entered the following strings:" << endl;
	for (const auto& str : str_list) {
		cout << str << endl;
	}
	return 0;
}