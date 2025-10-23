//Упражнение 1.22.Напишите программу, читающую несколько транзакций
//с одинаковым ISBN и отображающую сумму всех прочитанных транзакций.

#include "Sales_item.h"
#include <iostream>


int main() {
	Sales_item item1, item2, itemsum;
	bool first_item = false;
	while (std::cin >> item1) {
		if (first_item == false) {
			first_item = true;
			item2 = item1;
			continue;
		}
		if (item1.isbn() == item2.isbn()) {
			item2 += item1;
		} else {
			std::cout << "Sum of item: " << item2 << std::endl;
			item2 = item1;
		}
	}
	return 0;
}