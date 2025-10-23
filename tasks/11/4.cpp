//Упражнение 11.4.Усовершенствуйте свою программу так, чтобы
//игнорировать регистр и пунктуацию.Т.е.слова "example" и "Example", например,
//должны увеличить тот же счетчик.


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
		//// remove punct + to lower
		auto it = remove_if(str.begin(), str.end(), [](char& ch) {ch = tolower(ch); return ispunct(ch); });
		str.erase(it, str.end());
		//// exclude
		if (!str.empty() && exclude.find(str) == exclude.end()) {
			++counts[str];
		}
	}
	for (auto entry : counts) {
		cout << entry.first << " occurs " << entry.second << (entry.second == 1 ? " time" : " times") << endl;
	}
	return 0;
}