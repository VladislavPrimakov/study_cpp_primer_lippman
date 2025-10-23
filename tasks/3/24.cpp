//Упражнение 3.24.Переделайте последнее упражнение раздела 3.3.3
//(стр. 152) с использованием итераторов.

#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	int i;
	cout << "Enter a sequence of integers (CTRL+Z for stop):\n";
	while (cin >> i) {
		v.push_back(i);
	}
	cout << "You entered the following integers:\n";
	for (auto begin = v.cbegin(); begin != v.cend(); begin++) {
		cout << *begin << " ";
	}
	cout << endl;
	return 0;
}