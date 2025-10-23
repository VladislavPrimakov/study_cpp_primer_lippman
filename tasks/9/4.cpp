//Упражнение 9.4.Напишите функцию, которая получает два итератора
//вектора vector<int> и значение типа int.Организуйте поиск этого
//значения в диапазоне и возвратите логическое значение(тип bool),
//указывающее, что значение найдено.

#include <iostream>
#include <vector>
using namespace std;

bool find_value(vector<int>::const_iterator begin, vector<int>::const_iterator end, int value) {
	while (begin != end) {
		if (*begin == value) {
			return true;
		}
		++begin;
	}
	return false;
}

int main() {
	vector<int> vec = {1, 2, 3, 4, 5};
	cout << find_value(vec.cbegin(), vec.cend(), 3) << endl;
	cout << find_value(vec.cbegin(), vec.cend(), 6) << endl;

	return 0;
}