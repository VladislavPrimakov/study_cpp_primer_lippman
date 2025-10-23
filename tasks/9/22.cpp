//Упражнение 9.22.С учетом того, что iv является вектором целых чисел,
//что не так со следующей программой ? Как ее можно исправить ?
//vector<int>::iterator iter = iv.begin(),
//mid = iv.beginO + iv.size() / 2;
//while (iter != mid)
//if (*iter == some__val)
//iv.insert(iter, 2 * some_val);

#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> iv = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int some_val = 2;
	vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
	while (iter != mid) {
		if (*iter == some_val) {
			iter = iv.insert(iter, 2 * some_val);
			++iter;
			mid = iv.begin() + iv.size() / 2;
		}
		++iter;
	}
	for (const auto& num : iv) {
		cout << num << " ";
	}
	return 0;
}