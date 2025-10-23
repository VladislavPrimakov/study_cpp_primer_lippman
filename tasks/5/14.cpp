//”пражнение 5.14.Ќапишите программу дл€ чтени€ строк со стандартного
//устройства ввода и поиска совпадающих слов.ѕрограмма должна находить
//во вводе места, где одно слово непосредственно сопровождаетс€ таким же.
//ќтследите наибольшее количество повторений и повтор€емое слово.
//ќтобразите максимальное количество дубликатов или сообщение, что никаких
//повторений не было.Ќапример, при вводе how now now now brown cow
//cow вывод должен указать, что слово now встретилось три раза.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<string> words;
	vector<int> counts;
	string s;
	cout << "Enter text: ";
	while (cin >> s) {
		words.push_back(s);
		counts.push_back(0);
	}
	for (auto w : words) {
		for (size_t i = 0; i < words.size(); i++) {
			if (w == words[i]) {
				++counts[i];
			}
		}
	}
	size_t max = 0;
	size_t index = 0;
	for (size_t i = 0; i < counts.size(); i++) {
		if (counts[i] > max) {
			max = i;
			index = i;
		}
	}
	cout << "The word '" << words[index] << "' is repeated " << counts[index] << " times." << endl;
}