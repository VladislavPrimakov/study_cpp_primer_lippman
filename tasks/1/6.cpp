//Упражнение 1.6.Объясните, является ли следующий фрагмент кода
//допустимым :
//std::cout << "The sum of " << vl;
//<< " and " « v2;
//<< " is " << vl + v2 << std::endl;
//Если программа корректна, то что она делает ? Если нет, то почему и как ее
//исправить ?

#include <iostream>

int main() {
	int v1 = 5;
	int v2 = 10;
	std::cout << "The sum of " << v1
		<< " and " << v2
		<< " is " << v1 + v2 << std::endl;
	return 0;
}