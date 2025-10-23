//Упражнение 10.34.Используйте итератор reverseiterator для вывода
//содержимого вектора в обратном порядке.

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v = {0,1,2,3,4,5};
	for_each(v.crbegin(), v.crend(), [](const int& i) {cout << i << " "; });
	return 0;
}