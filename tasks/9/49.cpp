//”пражнение 9.49.” символов может быть надстрочна€ часть,
//расположенна€ выше середины строки, как у d или f, или подстрочна€, ниже середины
//строки, как p или g.Ќапишите программу, котора€ читает содержащий
//слова файл и сообщает самое длинное слово, не содержащее ни
//надстрочных, ни подстрочных элементов.

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	stringstream ss("A deep, fragrant garden offered happy frogs shelter, while the small cat sat near a warm stone in the sun");
	string word, longest_word;
	while (ss >> word) {
		auto i = word.find_first_of("dfpg");
		if (word.size() > longest_word.size() && word.find_first_of("dfpg") == string::npos) {
			longest_word = word;
		}
	}
	cout << "Base sting: " << ss.str() << endl;
	cout << "The longest word without ascenders or descenders is: " << longest_word << endl;
	return 0;
}