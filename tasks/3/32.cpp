//Упражнение 3.32.Скопируйте массив, определенный в предыдущем
//упражнении, в другой массив.Перезапишите эту программу так, чтобы
//использовались векторы.

#include <iostream>
using namespace std;
#include <vector>

int main() {
	const size_t size = 10;
	int arr[size];
	int arr_copy[size];
	for (int i = 0; i < 10; ++i) {
		arr[i] = i;
		arr_copy[i] = arr[i];
	}
	cout << "Copied array: ";
	for (auto& e : arr_copy) {
		cout << e << " ";
	}
	vector<int> vec(size);
	for (int i = 0; i < size; ++i) {
		vec[i] = arr[i];
	}
	cout << "\nCopied array using vector: ";
	for (const auto& e : vec) {
		cout << e << " ";
	}
	return 0;
}