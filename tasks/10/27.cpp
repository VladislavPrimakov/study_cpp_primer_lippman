//Упражнение 10.27.В дополнение к функции unique() (см.раздел 10.2.3, стр.492) библиотека определяет функцию uniquecopy(), получающую
//	третий итератор, обозначающий назначение копирования уникальных
//	элементов.Напишите программу, которая использует функцию
//	uniquecopy() для копирования уникальных элементов вектора в
//	первоначально пустой список.

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
	vector<int> v = {1,2,3,4,5,6,7,8,9,2,3,4};
	vector<int> c;
	sort(v.begin(), v.end());
	unique_copy(v.begin(), v.end(), back_inserter(c));
	for_each(c.begin(), c.end(), [](int& i) {cout << i << " "; });
	return 0;
}