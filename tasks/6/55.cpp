//Упражнение 6.55.Напишите четыре функции, которые добавляют,
//вычитают, умножают и делят два значения типа int.Сохраните указатели на эти
//значения в векторе из предыдущего упражнения.

#include <iostream>
#include <vector>
using namespace std;

int add(int& a, int& b) {
	return a + b;
}

int subtract(int& a, int& b) {
	return a - b;
}

int multiply(int& a, int& b) {
	return a * b;
}

int divide(int& a, int& b) {
	return a / b;
}

int main() {
	vector<int(*)(int&, int&)> vec;
	vec.push_back(add);
	vec.push_back(subtract);
	vec.push_back(multiply);
	vec.push_back(divide);
	int x = 20, y = 10;
	for (auto p : vec) {
		cout << p(x, y) << endl;
	}
	return 0;
}