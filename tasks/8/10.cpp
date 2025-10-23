//Упражнение 8.10.Напишите программу для сохранения каждой строки из
//файла в векторе vector<string>.Затем используйте объект класса
//istringstream для чтения каждого элемента из вектора по одному слову
//за раз.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 2) {
		cerr << "Usage: " << argv[0] << " <input file>" << endl;
		return -1;
	}
	ifstream in(argv[1]);
	if (!in) {
		cerr << "Could not open the input file!" << endl;
		return -1;
	}
	vector<string> lines;
	string line;
	while (getline(in, line)) {
		lines.push_back(line);
	}
	for (const auto& str : lines) {
		istringstream iss(str);
		string word;
		while (iss >> word) {
			cout << word << endl;
		}
	}
	return 0;
}