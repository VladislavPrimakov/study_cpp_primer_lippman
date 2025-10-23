//Упражнение 10.6.Напишите программу, использующую функцию
//fill_n() для обнуления последовательности целых чисел.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector <int> v = {1,2,3,4,5,6,3,3,2};
	fill_n(v.begin(), v.size(), 0);
	for (auto i : v) cout << i << " ";
	return 0;
}