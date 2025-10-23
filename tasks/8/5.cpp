//Упражнение 8.5.Перепишите предыдущую программу так, чтобы каждое
//слово сохранялось в отдельном элементе.

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
	while (infile >> line) {
		lines.push_back(line);
	}
	infile.close();
	for (const auto& str : lines) {
		cout << str << endl;
	}
	return 0;
}