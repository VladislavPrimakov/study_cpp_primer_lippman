//Упражнение 14.20.Определите оператор суммы и составной оператор
//присвоения для класса Salesdata.

#include "Sales_data.h"
using namespace std;

int main() {
	Sales_data data1("978-7-121-15535-2", 10, 59.8);
	Sales_data data2("978-7-121-15535-2", 5, 29.9);
	Sales_data data3 = data1 + data2;
	cout << data3 << endl;
	Sales_data data4(data1);
	data4 += data3;
	cout << data4 << endl;
	return 0;
}