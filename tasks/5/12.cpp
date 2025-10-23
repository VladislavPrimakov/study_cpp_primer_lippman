//Упражнение 5.12.Измените рассматриваемую программу так, чтобы она
//подсчитывала количество встреченных двухсимвольных
//последовательностей : ff, f1 и fi.

#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cout << "Enter text: ";
	getline(cin, s);
	int vowels = 0;
	int spaces = 0;
	int tabs = 0;
	int newlines = 0;
	int num_ff = 0;
	int num_fl = 0;
	int num_fi = 0;
	char prev = '\0';
	for (char c : s) {
		if (prev == 'f') {
			if (c == 'f')
				++num_ff;
			else if (c == 'l')
				++num_fl;
			else if (c == 'i')
				++num_fi;
		}
		if (c == 'a' || c == 'A')
			++vowels;
		else if (c == 'e' || c == 'E')
			++vowels;
		else if (c == 'i' || c == 'I')
			++vowels;
		else if (c == 'o' || c == 'O')
			++vowels;
		else if (c == 'u' || c == 'U')
			++vowels;
		else if (c == ' ')
			++spaces;
		else if (c == '\t')
			++tabs;
		else if (c == '\n')
			++newlines;
		prev = c;
	}
	cout << "Number of vowels: " << vowels << endl;
	cout << "Number of spaces: " << spaces << endl;
	cout << "Number of tabs: " << tabs << endl;
	cout << "Number of newlines: " << newlines << endl;
	cout << "Number of 'ff' sequences: " << num_ff << endl;
	cout << "Number of 'fl' sequences: " << num_fl << endl;
	cout << "Number of 'fi' sequences: " << num_fi << endl;
	return 0;
}