//Упражнение 16.6.Как работают библиотечные функции begin() и end(),
//получающие аргумент в виде массива ? Определите собственные версии
//этих функций.

#include <iostream>
using namespace std;

namespace my {
	template <typename T, size_t N>
	T* begin(T(&arr)[N]) {
		return &arr[0];
	}

	template <typename T, size_t N>
	T* end(T(&arr)[N]) {
		return &arr[0] + N;
	}
}

int main() {
	int intArr[] = {1, 2, 3, 4, 5};
	double doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	string stringArr[] = {"apple", "banana", "cherry"};
	cout << "Integer array: ";
	for (auto it = my::begin(intArr); it != my::end(intArr); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	cout << "Double array: ";
	for (auto it = my::begin(doubleArr); it != my::end(doubleArr); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	cout << "String array: ";
	for (auto it = my::begin(stringArr); it != my::end(stringArr); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}