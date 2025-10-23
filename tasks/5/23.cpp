//Упражнение 5.23.Напишите программу, которая читает два целых числа
//со стандартного устройства ввода и выводит результат деления первого
//числа на второе.


#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
	int a, b;
	cout << "Enter two integers (a b): ";

	while (cin >> a >> b) {
		try {
			if (b == 0) {
				throw(invalid_argument("Second number is 0"));
			}
		} catch (invalid_argument ex) {
			cout << ex.what() << endl;
			while (b == 0) {
				cout << "Enter again b: ";
				cin >> b;
			}
		}
		cout << "Result of " << a << " / " << b << " = " << static_cast<double>(a) / b << endl;
		cout << "Enter two integers (a b): ";
	}
	return 0;
}