//Упражнение 10.20.Библиотека определяет алгоритм countif().Подобно
//алгоритму findif(), он получает пару итераторов, обозначающих
//исходный диапазон и предикат, применяемый к каждому элементу заданного
//диапазона.Функция countif() возвращает количество раз, когда
//предикат вернул значение true.Используйте алгоритм countif(), чтобы
//переписать ту часть программы, которая рассчитывала количество слов длиной
//больше 6.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	vector<string> words = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
	int sz = 4;
	auto count = count_if(words.begin(), words.end(), [&sz](const string& s) { return s.size() > sz; });
	cout << count << endl;
	return 0;
}