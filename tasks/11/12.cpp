//Упражнение 11.12.Напишите программу, читающую последовательность
//строк и целых чисел, сохраняя каждую прочитанную пару в объекте класса
//pair.Сохраните пары в векторе.

#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
	vector<pair<string, int>> v;
	cout << "Enter <string> <int> (CTRL+Z to stop):" << endl;
	int i;
	string s;
	while (cin >> s >> i) {
		v.push_back({s,i});
	}
	for (auto& entry : v) {
		cout << "String: " << entry.first << " Int: " << entry.second << endl;
	}
	return 0;
}