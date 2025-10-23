//Упражнение 3.20.Прочитайте набор целых чисел в вектор.Отобразите
//сумму каждой пары соседних элементов.Измените программу так, чтобы
//она отображала сумму первого и последнего элементов, затем сумму
//второго и предпоследнего и т.д.


#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	cout << "Enter integers (end with Ctrl+D):" << endl;
	int tmp;
	while (cin >> tmp) {
		v.push_back(tmp);
	}
	cout << "Sum of adjacent elements:" << endl;
	for (size_t i = 0; i < v.size(); i += 2) {
		if (i + 1 < v.size()) {
			cout << v[i] + v[i + 1] << " ";
		}
	}
	cout << endl << "Sum of first and last, second and second last elements..:" << endl;
	for (size_t i = 0; i < v.size() / 2; ++i) {
		cout << v[i] + v[v.size() - 1 - i] << " ";
	}
	return 0;
}