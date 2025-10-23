//”пражнение 6.36.Ќапишите объ€вление функции, возвращающей ссылку
//на массив из дес€ти строк, не использу€ ни замыкающий тип
//возвращаемого значени€, ни спецификатор decltype или псевдоним типа.

#include <iostream>
#include <string>
using namespace std;

const string(&func(const string(&arr)[10]))[10]{
	return  arr;
}


int main() {
	string arr[10] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
	const string(&ref)[10] = func(arr);
	for (auto s : ref) {
		cout << s << " ";
	}
	return 0;
}