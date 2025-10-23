//Упражнение 10.35.Теперь отобразите элементы в обратном порядке,
//используя обычные итераторы.

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v = {0,1,2,3,4,5};
	for (auto it = v.begin(); it != v.end(); ++it) {
		cout << *(v.begin() + (v.end() - it - 1)) << " ";
	}
	return 0;
}