//Упражнение 5.17.Предположим, есть два вектора целых чисел.Напишите
//программу, определяющую, не является ли один вектор префиксом
//другого.Для векторов неравной длины сравнивайте количество элементов
//меньшего вектора.Например, если векторы содержат значения 0, 1, 1, 2 и О, 1, 1,
//2, 3, 5, 8 соответственно, ваша программа должна возвратить true.

#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v1;
	vector<int> v2;
	int tmp = 0;
	cout << "Enter integers for vector 1 (-1 for end): ";
	while (cin >> tmp && tmp != -1) {
		v1.push_back(tmp);
	}
	cout << "Enter integers for vector 2 (-1 for end): ";
	while (cin >> tmp && tmp != -1) {
		v2.push_back(tmp);
	}
	vector<int>& lower_vec = v1, & higher_vec = v2;
	if (v1.size() > v2.size()) {
		lower_vec = v2;
		higher_vec = v1;
	}
	bool is_prefix = false;
	if (lower_vec.size() != 0) {
		int first_value = lower_vec[0];
		for (size_t h = 0; h < higher_vec.size(); ++h) {
			if (is_prefix) {
				break;
			}
			if (higher_vec[h] == first_value) {
				for (size_t l = 0, h_tmp = h; l < lower_vec.size() && h_tmp < higher_vec.size(); ++l, ++h_tmp) {
					if (lower_vec[l] != higher_vec[h_tmp]) {
						break;
					}
					if (l == lower_vec.size() - 1) {
						is_prefix = true;
						break;
					}
				}
			}
		}
	}
	cout << (is_prefix ? "One vector is a prefix of another" : "No vector is a prefix of another") << endl;
}