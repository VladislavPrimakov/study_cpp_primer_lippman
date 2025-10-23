//Упражнение 11.20.Перепишите программу подсчета слов из раздела 11.1
//(стр.539) так, чтобы использовать функцию insert() вместо индексации.
//Какая версия программы по - вашему проще ? Объясните почему.

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	vector<string> text = {"Example,", "The", "the!", "123", "example.", "use"};
	set<string> exclude = {"the"};
	map <string, size_t> counts;
	for (auto str : text) {
		if (str.empty()) {
			continue;
		}
		// remove punct
		str.erase(partition(str.begin(), str.end(), [](char& ch) {return !ispunct(ch); }), str.end());
		// to lower
		for_each(str.begin(), str.end(), [](char& ch) {ch = tolower(ch); });
		// exclude
		if (exclude.find(str) == exclude.end()) {
			auto it = counts.insert({str, 1});
			if (!it.second) {
				++it.first->second;
			}
		}
	}
	for (auto entry : counts) {
		cout << entry.first << " occurs " << entry.second << (entry.second == 1 ? " time" : " times") << endl;
	}
	return 0;
}