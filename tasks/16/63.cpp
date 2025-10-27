//Упражнение 16.63.Определите шаблон функции для подсчета количества
//вхождений заданного значения в векторе.Проверьте программу, передав ей
//вектор значений типа double, вектор целых чисел и вектор строк.

#include <vector>
#include <string>
#include <iostream>
using namespace std;

template <typename T, typename U>
size_t count_elem_vec(const vector<T>& v, const U& elem) {
	size_t count = 0;
	for (const auto& e : v) {
		if (e == elem) {
			++count;
		}
	}
	return count;
}

int main() {
	vector<int> v1 = {1,2,3,4,5};
	vector<double> v2 = {1.0, 2.0, 3.0, 4.0, 5.0};
	vector<string> v3 = {"Hello", "world", "Hello"};
	cout << "Count elem int vec: " << count_elem_vec(v1, 2) << endl;
	cout << "Count elem double vec: " << count_elem_vec(v2, 2.0) << endl;
	cout << "Count elem string vec: " << count_elem_vec(v3, "Hello") << endl;
	return 0;
}