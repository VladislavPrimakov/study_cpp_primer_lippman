//Упражнение 9.5.Перепишите предыдущую программу так, чтобы она
//возвращала итератор на найденный элемент.Функция должна учитывать
//случай, когда элемент не найден.

#include <iostream>
#include <vector>
using namespace std;

vector<int>::const_iterator find_value(vector<int>::const_iterator begin, vector<int>::const_iterator end, int value) {
	while (begin != end) {
		if (*begin == value) {
			return begin;
		}
		++begin;
	}
	return end;
}

int main() {
	vector<int> vec = {1, 2, 3, 4, 5};
	auto it = find_value(vec.cbegin(), vec.cend(), 3);
	if (it != vec.cend())
		cout << "Found: " << *it << endl;
	else
		cout << "Not found" << endl;

	it = find_value(vec.cbegin(), vec.cend(), 6);
	if (it != vec.cend())
		cout << "Found: " << *it << endl;
	else
		cout << "Not found" << endl;


	return 0;
}