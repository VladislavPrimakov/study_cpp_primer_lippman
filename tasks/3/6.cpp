//”пражнение 3.6.»спользуйте серийный оператор for дл€ замены всех
//символов строки на х.

#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cout << "Enter a string:\n";
	getline(cin, s);
	for (auto& ch : s) {
		ch = 'x';
	}
	cout << "Modified string:\n" << s << endl;
	return 0;
}