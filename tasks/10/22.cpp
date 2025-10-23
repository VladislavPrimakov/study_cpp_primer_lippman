//Упражнение 10.22.Перепишите программу подсчета слов размером 6
//символов с использованием функций вместо лямбда - выражений.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;

bool f(const string& s, int sz) {
	return s.size() > sz;
}


int main() {
	vector<string> words = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
	int sz = 4;
	auto count = count_if(words.begin(), words.end(), bind(f, _1, sz));
	cout << count << endl;
	return 0;
}