//”пражнение 9.34.”читыва€, что vi €вл€етс€ контейнером целых чисел,
//содержащим четные и нечетные значени€, предскажите поведение
//следующего цикла.ѕроанализировав этот цикл, напишите программу, чтобы
//проверить правильность своих ожиданий.
//iter = vi.begin();
//while (iter != vi.endO)
//if (*iter % 2)
//iter = vi.insert(iter, *iter);
//++iter;

#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto iter = vi.begin();
	while (iter != vi.end()) {
		if (*iter % 2) {
			iter = vi.insert(iter, *iter);
			++iter;
		}
		++iter;
	}
	for (const auto& i : vi) {
		cout << i << " ";
	}
	return 0;
}