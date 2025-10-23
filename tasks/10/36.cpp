//Упражнение 10.36.Используйте функцию find() для поиска в списке
//целых чисел последнего элемента со значением 0.

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	vector<int> v = {0,1,2,3,4,0,5};
	int elem = 0;
	auto it = find(v.rbegin(), v.rend(), elem);
	cout << "Last element: " << *it;
	return 0;
}