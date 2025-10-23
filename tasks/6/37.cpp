//Упражнение 6.37.Напишите три дополнительных объявления для функций
//предыдущего упражнения.Нужно использовать псевдоним типа,
//замыкающий тип возвращаемого значения и спецификатор decltype.Какую
//форму вы предпочитаете и почему ?

#include <iostream>
#include <string>
using namespace std;

string arr[10] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};

const string(&f_const(const string(&arr)[10]))[10]{
	return  arr;
}

auto f_auto(const string(&arr)[10]) -> const string(&)[10] {
	return arr;
}

const decltype(arr)& f_decltype(const string(&arr)[10]) {
	return arr;
}

int main() {

	cout << "Using const:" << endl;
	const string(&ref1)[10] = f_const(arr);
	for (auto s : ref1) {
		cout << s << " ";
	}
	cout << endl << "Using auto:" << endl;
	const string(&ref2)[10] = f_auto(arr);
	for (auto s : ref2) {
		cout << s << " ";
	}
	cout << endl << "Using decltype:" << endl;
	const string(&ref3)[10] = f_decltype(arr);
	for (auto s : ref3) {
		cout << s << " ";
	}
	return 0;
}