//Упражнение 6.33.Напишите рекурсивную функцию, выводящую
//содержимое вектора.

#include <iostream>
#include <vector>
using namespace std;

void print_vector(const vector<int>& v, size_t index = 0) {
	if (index >= v.size()) return;
	cout << v[index] << " ";
	print_vector(v, index + 1);
}


int main() {
	vector<int> v = {1,2,3,4,5,6,7,8,9,10};
	print_vector(v);
	return 0;
}