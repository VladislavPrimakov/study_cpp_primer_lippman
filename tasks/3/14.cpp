//Упражнение 3.14.Напишите программу, читающую последовательность
//целых чисел из потока сin и сохраняющую их в векторе.

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
	for (auto& num : v) {
		cout << num << " ";
	}
	cout << endl;
	return 0;
}