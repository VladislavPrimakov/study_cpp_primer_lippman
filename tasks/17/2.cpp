//”пражнение 17.2.ќпределите кортеж, содержащий строку, вектор
//строки и пару из строки и целого числа(типы string, vector<string>
//									   и pair<string, int>).

#include <tuple>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	tuple<string, vector<string>, pair<string, int>> t {"String", {"Vector", "String"}, {"String pair", 10}};
	cout << get<2>(t).first << endl;
	return 0;
}