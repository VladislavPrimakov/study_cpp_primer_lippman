//Упражнение 3.25.Перепишите программу кластеризации оценок из
//раздела 3.3.3 (стр. 150) с использованием итераторов вместо индексации.
// подсчет количества оценок в кластере по десять: 0--9,


#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<unsigned> scores(11, 0);
	unsigned grade;
	cout << "Enter the grades (0-100) (CTRL+Z for stop):" << endl;
	while (cin >> grade) {
		if (grade <= 100) {
			auto it = scores.begin() + grade / 10;
			*it += 1;
		}
	}
	for (auto it = scores.cbegin(); it != scores.cend(); ++it) {
		cout << *it << " ";
	}
	return 0;
}