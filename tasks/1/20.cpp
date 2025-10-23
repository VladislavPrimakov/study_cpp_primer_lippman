//Упражнение 1.20.По адресу http://www.informit.com/title/032174113
//в каталоге кода первой главы содержится копия файла Salesi tern.h.
//Скопируйте этот файл в свой рабочий каталог и используйте при написании
//программы, которая читает набор транзакций проданных книг и отображает их
//на стандартном устройстве вывода.

#include "Sales_item.h"
#include <iostream>

int main() {
	Sales_item item;
	// read the data for the item
	while (std::cin >> item) {
		// write the item to the standard output
		std::cout << item << std::endl;
	}
	return 0;
}