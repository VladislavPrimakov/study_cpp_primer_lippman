//Упражнение 10.29.Напишите программу, использующую потоковые
//итераторы для чтения текстового файла в вектор строк.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

int main(int argc, char* argv[]) {
	if (argc < 2) {
		cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
		return -1;
	}
	ifstream file(argv[1]);
	if (!file.is_open()) {
		cerr << "File not found";
		return -1;
	}
	istream_iterator<string> ii(file), eof;
	vector<string> v(ii, eof);
	for (auto& s : v) {
		cout << s << " ";
	}
	return 0;
}