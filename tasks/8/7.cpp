//Упражнение 8.7.Пересмотрите программу книжного магазина из
//предыдущего раздела так, чтобы вывод записывался в файл.Передайте имя этого
//файла как второй аргумент функции main().

#include <iostream>
#include <fstream>
#include <string>
#include "Sales_data.h"
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
	ofstream out(string(argv[1]) + ".copy");
	if (!out) {
		cerr << "Could not open the output file!" << endl;
		return -1;
	}
	Sales_data total, trans;
	if (read(in, total)) {
		while (read(in, trans)) {
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			} else {
				print(out, total) << endl;
				total = trans;
			}
		}
		print(out, total) << endl;
	} else {
		cerr << "No data?!" << endl;
	}
	return 0;
}