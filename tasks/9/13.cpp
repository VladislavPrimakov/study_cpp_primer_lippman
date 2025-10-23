//Упражнение 9.13.Как инициализировать контейнер vector<double> из
//контейнера list<int> и контейнера vector<in - t> ? Напишите код для
//проверки ответов.

#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> vec_int = {1, 2, 3, 4, 5};
	vector<double> vec_double_from_int(vec_int.begin(), vec_int.end());
	cout << "Vector of doubles initialized from vector of ints: ";
	for (const auto& val : vec_double_from_int) {
		cout << val << " ";
	}
	cout << endl;
	return 0;
}