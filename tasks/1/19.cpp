//Упражнение 1.19.Пересмотрите свою программу, написанную для
//упражнения раздела 1.4.1 (стр. 39), которая выводила бы диапазон чисел,
//обрабатывая ввод, так, чтобы первым отображалось меньше число из двух введенных.

#include <iostream>
#include <utility>

int main() {
	int num1, num2;
	std::cout << "Enter two integers: ";
	std::cin >> num1 >> num2;
	if (num1 > num2) {
		std::swap(num1, num2);
	}
	while (num1 <= num2) {
		std::cout << num1 << std::endl;
		++num1;
	}
	return 0;
}