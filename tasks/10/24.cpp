//Упражнение 10.24.Используйте функции bind() и checksize() для
//поиска первого элемента вектора целых чисел, значение которого больше
//длины заданного строкового значения.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;

bool check_size(const int& i, const string& s) {
	return i > s.size();
}


int main() {
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	string s = "Vect";
	auto it = find_if(v.begin(), v.end(), bind(check_size, _1, ref(s)));
	cout << *it << endl;
	return 0;
}