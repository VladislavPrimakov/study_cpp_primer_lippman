#ifndef REGEXPHONE_H
#define REGEXPHONE_H

#include <regex>
#include <string>
#include <vector>
using namespace std;

regex pattern_phone(R"(^(\+)?(380)?([ -]?)(0)?(\d{2})([ -]?)(\d{3})([ -]?)(\d{2})([ -]?)(\d{2})$)");
regex pattern_phone_format(R"(^\+380 (\d{2}) (\d{3}) (\d{2}) (\d{2})$)");

bool is_valid_phone_number(const smatch& m) {
	if (m.size() != 12) {
		return false;
	}
	if (m[1].matched && !m[2].matched) {
		return false;
	}
	if (m[2].matched && m[4].matched) {
		return false;
	}
	if (!m[2].matched && !m[4].matched) {
		return false;
	}
	bool check_sep = m[6].str() != m[8].str() || m[8].str() != m[10].str();
	if (check_sep) {
		return false;
	}
	if (m[2].matched && (m[3].str() != m[6].str())) {
		return false;
	}
	return true;
}

string format_phone_number(const string& number) {
	string s = regex_replace(number, pattern_phone, R"(+380 $5 $7 $9 $11)", regex_constants::format_no_copy);
	return s;
}

vector<pair<string, bool>> test_numbers = {
	// Expected to PASS validation
	{"+380991234567",   true},
	{"380991234567",    true},
	{"+380 99 123 45 67",true},
	{"+380-99-123-45-67",true},
	{"0991234567",      true},
	{"099 123 45 67",   true},
	{"099-123-45-67",   true},

	// Expected to FAIL validation
	{"+0991234567",     false}, // Fail: '+' present, but '380' is missing
	{"+3800991234567",  false}, // Fail: Both '380' and leading '0' are present
	{"991234567",       false}, // Fail: Neither '380' nor leading '0' is present
	{"+38099-1234567",  false}, // Fail: Inconsistent separators (missing vs present)
	{"099 123-45 67",   false}, // Fail: Inconsistent separators (space vs hyphen vs space)
	{"+38099123456",    false}, // Fails regex match (too short)
	{"09912345678",     false}, // Fails regex match (too long)
	{"099 123 456",     false}, // Fails regex match (too short)
	{"099-12-34-56",    false}  // Fails regex match (wrong digit group counts)
};
#endif // !REGEXPHONE_H