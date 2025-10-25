//Упражнение 16.7.Напишите шаблон constexpr, возвращающий размер
//заданного массива.

#include <iostream>
using namespace std;

namespace my {
	template <typename T, size_t N>
	constexpr size_t arraySize(T(&arr)[N]) {
		return N;
	}
}

int main() {
	int intArr[] = {1, 2, 3, 4, 5};
	double doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	string stringArr[] = {"apple", "banana", "cherry"};
	cout << "Size of integer array: " << my::arraySize(intArr) << endl;
	cout << "Size of double array: " << my::arraySize(doubleArr) << endl;
	cout << "Size of string array: " << my::arraySize(stringArr) << endl;
	return 0;
}