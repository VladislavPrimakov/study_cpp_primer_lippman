//Упражнение 3.35.Напишите программу, которая использует указатели для
//обнуления элементов массива.

#include <iostream>
using namespace std;

int main() {
	const size_t size = 10;
	int arr[size];
	for (int i = 0; i < size; ++i) {
		arr[i] = i;
	}
	cout << "Original array: ";
	for (const auto& e : arr) {
		cout << e << " ";
	}
	cout << endl;
	int* p = arr;
	for (size_t i = 0; i < size; ++i) {
		*(p + i) = 0;
	}
	cout << "Array after zeroing elements: ";
	for (const auto& e : arr) {
		cout << e << " ";
	}
	cout << endl;
	return 0;
}