//Упражнение 3.10.Напишите программу, которая читает строку символов,
//включающую знаки пунктуации, и выведите ее, но уже без знаков пунктуации.

#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "Enter a string:\n";
	string s, sWithoutPunct;
	getline(cin, s);
	for (auto& ch : s) {
		if (!ispunct(ch)) {
			sWithoutPunct += ch;
		}
	}
	cout << "String without punctuation:\n" << sWithoutPunct << endl;
	return 0;
}
