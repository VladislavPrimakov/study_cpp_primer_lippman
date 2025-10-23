//Упражнение 7.1.Напишите версию программы обработки транзакций из
//раздела 1.6 (стр.52) с использованием класса Salesdata, созданного для
//упражнений в разделе 2.6.1 (стр. 112).

#include <iostream>
#include "Sales_data.h"
using namespace std;

int main() {
	Sales_data total, trans;
	if (read(cin, total)) {
		while (read(cin, trans)) {
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			} else {
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
	} else {
		cerr << "No data?!" << endl;
	}
	return 0;
}