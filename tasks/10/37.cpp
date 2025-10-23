//Упражнение 10.37.С учетом того, что вектор содержит 10 элементов,
//скопируйте в список диапазон его элементов от позиции 3 до позиции 7 в
//обратном порядке.

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	vector<int> v = {0,1,2,3,4,5,6,7,8,9};
	vector<int> c(v.rbegin() + 2, v.rbegin() + 7);
	for (auto& i : c) {
		cout << i << " ";
	}
	return 0;
}