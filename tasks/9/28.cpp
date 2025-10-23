//Упражнение 9.28.Напишите функцию, получающую контейнер
//forward_list<string> и два дополнительных аргумента типа string.
//Функция должна находить первую строку и вставлять вторую
//непосредственно после первой.Если первая строка не найдена, то вставьте вторую
//строку в конец списка.

#include <iostream>
#include <forward_list>
#include <string>
using namespace std;

void insert_after_string(forward_list<string>& fl, const string& str1, const string& str2) {
	auto prev = fl.before_begin();
	auto curr = fl.begin();
	while (curr != fl.end()) {
		if (*curr == str1) {
			fl.insert_after(curr, str2);
			return;
		}
		++prev;
		++curr;
	}
	fl.insert_after(prev, str2);
}

int main() {
	forward_list<string> fl = {"apple", "banana", "cherry", "date"};
	string str1 = "banana";
	string str2 = "blueberry";
	insert_after_string(fl, str1, str2);
	for (const auto& s : fl) {
		cout << s << " ";
	}
	cout << endl;
	string str3 = "fig";
	string str4 = "grape";
	insert_after_string(fl, str3, str4);
	for (const auto& s : fl) {
		cout << s << " ";
	}
	return 0;
}