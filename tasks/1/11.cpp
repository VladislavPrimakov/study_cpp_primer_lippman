//Упражнение 1.11.Напишите программу, которая запрашивает у
//пользователя два целых числа, а затем отображает каждое число в диапазоне,
//определенном этими двумя числами.

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