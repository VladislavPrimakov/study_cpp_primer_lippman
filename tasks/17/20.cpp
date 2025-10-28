//Упражнение 17.20.Напишите собственную версию программы для
//проверки номеров телефонов.

#include "RegexPhone.h"
#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <cassert>
using namespace std;

void test(const bool& check, const bool& real) {
	assert(check == real);
}

int main() {
	try {
		regex pattern = pattern_phone;
		for (auto& p : test_numbers) {
			smatch result;
			bool matched = regex_match(p.first, result, pattern);
			auto check = is_valid_phone_number(result);
			cout << p.first << "\t | " << " -> " << check << endl;
			test(check, p.second);
		}
	} catch (regex_error err) {
		cout << err.what() << " | " << err.code() << endl;
	}
	return 0;
}