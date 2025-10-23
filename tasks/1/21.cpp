//Упражнение 1.21.Напишите программу, которая читает два объекта класса
//Salesitem с одинаковыми ISBN и вычисляет их сумму.
//Упражнение

#include "Sales_item.h"
#include <iostream>


int main() {
	Sales_item item1, item2;
	bool first_item = false;
	while (std::cin >> item1) {
		if (first_item == false) {
			first_item = true;
			item2 = item1;
			continue;
		}
		if (item1.isbn() == item2.isbn()) {
			std::cout << "Item1: " << item1 << std::endl;
			std::cout << "Item2: " << item2 << std::endl;
			std::cout << "Sum of the two items: " << item1 + item2 << std::endl;
			return 0;
		}
		item2 = item1;
	}
	return 0;
}