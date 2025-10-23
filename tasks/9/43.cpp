//Упражнение 9.43.Напишите функцию, получающую три строки : s, oldVal
//и newVal.Используя итераторы, а также функции insert(), и erase()
//замените все присутствующие в строке s экземпляры строки oldVal строкой
//newVal.Проверьте функцию на примере замены таких общепринятых
//сокращений, как "tho" на "though" и "thru" на "through".


#include <iostream>
#include <string>
using namespace std;

string& f(string& s, const string& oldVal, const string& newVal) {
	string::size_type index = 0;
	while ((index = s.find(oldVal, index)) != -1) {
		s.erase(index, oldVal.size());
		s.insert(index, newVal);
		index += newVal.size();
	}
	return s;
}

int main() {
	string s = "tho I went thru the tho";
	cout << f(s, "tho", "though") << endl;
	return 0;
}