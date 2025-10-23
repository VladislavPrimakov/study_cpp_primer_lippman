//”пражнение 5.11.»змените рассматриваемую программу так, чтобы она
//подсчитывала также количество пробелов, символов табул€ции и новой
//строки.

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
	for (char c : s) {
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
	}
	cout << "Number of vowels: " << vowels << endl;
	cout << "Number of spaces: " << spaces << endl;
	cout << "Number of tabs: " << tabs << endl;
	cout << "Number of newlines: " << newlines << endl;
	return 0;
}