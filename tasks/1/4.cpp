//Упражнение 1.4.Наша программа использовала оператор суммы(+) для
//сложения двух чисел.Напишите программу, которая использует оператор
//умножения(*) для вычисления произведения двух чисел.
//Упражнение В


#include <iostream>

int main()
{
	std::cout << "Enter two numbers:" << std::endl;
	int vl = 0, v2 = 0;
	std::cin >> vl >> v2;
	std::cout << "The multiplication of " << vl << " and " << v2 << " is " << vl * v2 << std::endl;
	return 0;
}