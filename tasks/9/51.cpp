//Упражнение 9.51.Напишите класс, у которого есть три беззнаковых члена,
//представляющих год, месяц и день.Напишите конструктор, получающий
//строку, представляющую дату.Конструктор должен понимать множество
//форматов даты, такие как January 1, 1900, 1 / 1 / 1900, Jan 1, 1900


#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdint>
using namespace std;

struct Date {
	uint8_t day;
	uint8_t month;
	uint16_t year;
	static const string months_to_int[12];
	Date(string s) {
		string s_no_punct, word;
		copy_if(s.begin(), s.end(), back_inserter(s_no_punct), [](char& c) { return !ispunct(c); });
		stringstream ss(s_no_punct);
		ss >> word;
		// month from string
		for (uint8_t i = 0; i < 12; ++i) {
			if (word.find(months_to_int[i]) != string::npos) {
				month = i + 1;
				break;
			}
		}
		// month from number
		if (month == 0) {
			from_chars(word.data(), word.data() + word.size(), month);
		}
		ss >> word;
		from_chars(word.data(), word.data() + word.size(), day);
		ss >> word;
		from_chars(word.data(), word.data() + word.size(), year);
	}
	void print() {
		printf("Date: %u.%u.%u\n", month, day, year);
	}
};

const string Date::months_to_int[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

int main() {
	vector<string> dates = {"January 1, 1901", "2 / 2 / 1902", "Jan 3, 1903"};
	for (const auto& s : dates) {
		Date d(s);
		d.print();
	}
	return 0;
}