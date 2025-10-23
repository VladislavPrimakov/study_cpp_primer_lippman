//Упражнение 6.4.Напишите взаимодействующую с пользователем
//функцию, которая запрашивает число и вычисляет его факториал.Вызовите эту
//функцию из функции main().

#include <iostream>
using namespace std;

unsigned long long factorial(int n) {
	if (n < 0) {
		cout << "Factorial is not defined for negative numbers." << endl;
	}
	unsigned long long result = 1;
	for (int i = 1; i <= n; ++i) {
		result *= i;
	}
	return result;
}

int main() {
	int number;
	cout << "Enter a non-negative integer: ";
	while (cin >> number) {
		if (number < 0) {
			cout << "Factorial is not defined for negative numbers." << endl;
		} else {
			auto result = factorial(number);
			cout << "Factorial of " << number << " is " << result << endl;
		}
		cout << "Enter a non-negative integer: ";
	}
	return 0;
}