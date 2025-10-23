//Упражнение 8.11.Программа этого раздела определила свой объект класса
//istringstream во внешнем цикле while.Какие изменения необходимо
//внести, чтобы определить объект record вне этого цикла ? Перепишите
//программу, перенеся определение объекта record во вне цикла while,
//и убедитесь, все ли необходимые изменения внесены.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;


struct PersonInfo {
	string name;
	vector<string> phones;
};


int main() {
	string all_data =
		R"(morgan 2015552368 8625550123
drew 9735550130
lee 6095550132 2015550175 8005550000)";
	istringstream input(all_data);

	string line, word;
	vector<PersonInfo> people;
	istringstream record;
	while (getline(input, line)) {
		PersonInfo info;
		record.str(line);
		record.clear();
		record >> info.name;
		while (record >> word) {
			info.phones.push_back(word);
		}
		people.push_back(info);
	}
	for (const auto& entry : people) {
		cout << entry.name << " ";
		for (const auto& phone : entry.phones) {
			cout << phone << " ";
		}
		cout << endl;
	}
}