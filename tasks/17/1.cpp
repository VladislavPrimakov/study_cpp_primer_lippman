//Упражнение 17.1.Определите кортеж, содержащий три члена типа int,
//и инициализируйте их значениями 10, 20 и 30.

#include <iostream>
#include <tuple>
using namespace std;

int main() {
	tuple<int, int, int> t {10, 20, 30};
	cout << get<0>(t);
	return 0;
}