//Упражнение 16.5.Напишите шаблон функции print() из раздела 6.2.4
//(стр. 286), которая получает ссылку на массив и может обрабатывать
//массивы любого размера и любого типа элементов.

#include <iostream>
using namespace std;

template <typename T, size_t N>
void print(const T(&arr)[N]) {
	for (size_t i = 0; i < N; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int intArr[] = {1, 2, 3, 4, 5};
	double doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	string stringArr[] = {"apple", "banana", "cherry"};
	print(intArr);
	print(doubleArr);
	print(stringArr);
	return 0;
}