//Упражнение 17.24.Напишите собственную версию программы для
//переформатирования номеров телефонов.

#include "RegexPhone.h"
#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <cassert>
using namespace std;

void test(const string& formatted, pair<string, bool> base) {
	smatch m;
	bool check = regex_match(formatted, m, pattern_phone_format);
	if (!check && !base.second) {
		return;
	}
	assert(check);
}

int main() {
	regex pattern = pattern_phone;
	for (auto& p : test_numbers) {
		string s = format_phone_number(p.first);
		cout << p.first << "\t-> " << s << endl;
		test(s, p);
	}
	return 0;
}