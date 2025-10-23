//Упражнение 6.47.Пересмотрите программу, написанную в упражнении
//раздела 6.3.2 (стр. 299), где использовалась рекурсия для отображения
//содержимого вектора так, чтобы условно отображать информацию о ее
//выполнении.Например, отобразите размер вектора при каждом вызове.
//Откомпилируйте и запустите программу с включенной отладкой и с
//выключенной.

//#define NDEBUG

#include <iostream>
#include <vector>
using namespace std;

void print_vector(const vector<int>& v, size_t index = 0) {
	if (index >= v.size()) return;
	cout << v[index] << " ";
#ifndef NDEBUG
	cout << endl << "Current index: " << index << endl;
#endif // !NDEBUG
	print_vector(v, index + 1);
}


int main() {
	vector<int> v = {1,2,3,4,5,6,7,8,9,10};
	print_vector(v);
	return 0;
}