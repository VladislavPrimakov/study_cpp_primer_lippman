//Упражнение 9.41.Напишите программу, инициализирующую строку из
//вектора vector<char>.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<char> vc = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
	string str(vc.begin(), vc.end());
	cout << str << endl;
	return 0;
}