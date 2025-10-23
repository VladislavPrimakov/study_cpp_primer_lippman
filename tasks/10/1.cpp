//Упражнение 10.1.В заголовке algorithm определена функция count(),
//подобная функции find О.Она получает два итератора и значение, а
//возвращает количество обнаруженных в диапазоне элементов, обладающих
//искомым значением.Организуйте чтение в вектор последовательности
//целых чисел.Осуществите подсчет элементов с указанным значением.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector <int> v = {1,2,3,4,5,6,3,3,2};
	int value = 3;
	cout << "Count of " << value << " is " << count(v.begin(), v.end(), value) << endl;
	return 0;
}