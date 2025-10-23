//j Упражнение 2.4.Напишите программу для проверки правильности отве -
//1 тов.При неправильных ответах изучите этот раздел еще раз.

#include <iostream>
#include <typeinfo>

int main() {
	unsigned u = 10, u2 = 42;
	std::cout << u2 - u << std::endl;
	std::cout << u - u2 << std::endl;
	int i = 10, i2 = 42;
	std::cout << 12 - i << std::endl;
	std::cout << i - i2 << std::endl;
	std::cout << i - u << std::endl;
	std::cout << u - i << std::endl;

	return 0;
}