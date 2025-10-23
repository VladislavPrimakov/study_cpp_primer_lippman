//Упражнение 9.50.Напишите программу обработки вектора
//vector<string>, элементы которого представляют целочисленные
//значения.Вычислите сумму всех элементов вектора.Измените программу так,
//чтобы она суммировала строки, которые представляют значения с
//плавающей точкой.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<string> vec_float = {"1.5", "2.3", "3.7", "4.0", "5.2"};
	vector<string> vec_int = {"1", "2", "3", "4", "5"};
	double sum_float = 0.0;
	int sum_int = 0;
	for (const auto& s : vec_float) {
		sum_float += stod(s);
	}
	for (const auto& s : vec_int) {
		sum_int += stoi(s);
	}
	cout << "Sum of floating-point values: " << sum_float << endl;
	cout << "Sum of integer values: " << sum_int << endl;
	return 0;
}