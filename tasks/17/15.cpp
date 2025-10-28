//Упражнение 17.15.Напишите программу, используя схему поиска слов,
//нарушающих правило "\ перед е, кроме как после с"'. Организуйте 
//приглашение для ввода пользователем слова и вывод результата его проверки.
//Проверьте свою программу на примере слов, которые нарушают и не
//нарушают это правило.

#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main() {
	regex pattern(R"(.*[^c]ei.*)", regex::icase);
	string word;
	cout << "Enter a word to check: ";
	while (cin >> word) {
		if (regex_search(word, pattern)) {
			cout << word << " violates the rule." << endl;
		} else {
			cout << word << " does not violate the rule." << endl;
		}
		cout << "Enter a word to check: ";
	}
	return 0;
}