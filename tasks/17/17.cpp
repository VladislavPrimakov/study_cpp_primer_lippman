//”пражнение 17.17.»змените свою программу так, чтобы она находила все
//слова в исходной последовательности, нарушающие правило "\ перед е,
//кроме как после с".

#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main() {
	regex pattern(R"(\S*[^c]ei\S*)", regex::icase);
	string s;
	cout << "Enter a line to check: " << endl;
	while (getline(cin, s)) {
		for (sregex_iterator it(s.cbegin(), s.cend(), pattern), end; it != end; ++it) {
			auto pos = it->prefix().length();
			pos = pos > 40 ? pos - 40 : 0;
			cout << it->prefix().str().substr(pos) << endl
				<< "\t>>> " << it->str() << " <<<\t" << endl
				<< it->suffix().str().substr(0, 40) << endl;
		}
		cout << "Enter a line to check: " << endl;
	}
	return 0;
}