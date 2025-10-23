//Упражнение 1.9.Напишите программу, которая использует цикл while
//для суммирования чисел от 50 до 100.

#include <iostream>

int main() {
	int sum = 0;
	int i = 50;
	while (i <= 100) {
		sum += i;
		++i;
	}
	std::cout << "The sum of numbers from 50 to 100 is " << sum << std::endl;
	return 0;
}