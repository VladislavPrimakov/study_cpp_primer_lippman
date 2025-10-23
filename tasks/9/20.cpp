//Упражнение 9.20.Напишите программу, копирующую элементы списка
//list<int> в две двухсторонние очереди, причем нечетные элементы
//должны копироваться в один контейнер deque, а четные в другой.

#include <iostream>
#include <list>
#include <deque>
using namespace std;

int main() {
	list<int> int_list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	deque<int> odd_deque;
	deque<int> even_deque;
	for (const auto& num : int_list) {
		if (num % 2 == 0) {
			even_deque.push_back(num);
		} else {
			odd_deque.push_back(num);
		}
	}
	cout << "Odd numbers in deque: ";
	for (const auto& num : odd_deque) {
		cout << num << " ";
	}
	cout << endl;
	cout << "Even numbers in deque: ";
	for (const auto& num : even_deque) {
		cout << num << " ";
	}
	cout << endl;
	return 0;
}