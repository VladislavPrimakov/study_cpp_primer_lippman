//Упражнение 3.8.Перепишите программу первого упражнения, сначала
//используя оператор while, а затем традиционный цикл for.Какой из этих
//трех подходов вы предпочтете и почему ?


#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cout << "Enter a string:\n";
	getline(cin, s);
	size_t i = 0;
	while (i < s.size()) {
		s[i] = 'x';
		++i;
	}
	cout << "Modified string:\n" << s << endl;

	for (size_t i = 0; i < s.size(); i++) {
		s[i] = 'x';
	}
	cout << "Modified string:\n" << s << endl;
	return 0;
}