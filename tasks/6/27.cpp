//Упражнение 6.27.Напишите функцию, получающую параметр типа
//initializer_list<int> и возвращающую сумму элементов списка.

#include <initializer_list>
#include <iostream>
using namespace std;

int sum(initializer_list<int> il) {
	int sum = 0;
	for (int n : il) {
		sum += n;
	}
	return sum;
}

int main() {
	cout << "Sum {1,2,3,4,5}: " << sum({1, 2, 3, 4, 5}) << endl;
	return 0;
}