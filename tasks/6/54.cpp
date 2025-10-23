//”пражнение 6.54.Ќапишите объ€вление функции, получающей два
//параметра типа int, и возвращающей тип int.ќбъ€вите также вектор,
//элементами которого €вл€етс€ тип указател€ на эту функцию.

#include <iostream>
#include <vector>
using namespace std;

int& f(int& a, int& b) {
	return a > b ? a : b;
}

int main() {
	vector<int& (*)(int&, int&)> vec;
	vec.push_back(f);
	for (auto p : vec) {
		int x = 10, y = 20;
		cout << p(x, y) << endl;
	}
	return 0;
}