//���������� 7.13.���������� ��������� �� ���. 333 ���, �����
//������������ ����������� � ���������� istream.

#include <iostream>
#include "Sales_data.h"
using namespace std;

int main() {
	if (cin) {
		Sales_data total(cin);
		while (cin) {
			Sales_data trans(cin);
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			} else {
				print(cout, total) << endl;
				total = trans;
			}
		}
		if (!total.isbn().empty()) {
			print(cout, total) << endl;
		}
	} else {
		cerr << "No data?!" << endl;
	}
	return 0;
}