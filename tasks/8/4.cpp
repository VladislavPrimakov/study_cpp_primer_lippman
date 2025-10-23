//Упражнение 8.4.Напишите функцию, которая открывает файл и читает
//его содержимое в вектор строк, сохраняя каждую строку как отдельный
//элемент вектора.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main() {
	ifstream infile("data/input.txt");
	if (!infile) {
		cerr << "Could not open the file!" << endl;
		return 1;
	}
	vector<string> lines;
	string line;
	while (getline(infile, line)) {
		lines.push_back(line);
	}
	infile.close();
	// Output the lines to verify
	for (const auto& str : lines) {
		cout << str << endl;
	}
	return 0;
}