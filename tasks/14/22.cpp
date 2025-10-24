//”пражнение 14.22.ќпределите версию оператора присвоени€, способного
//присвоить строку, представл€ющую ISBN, объекту класса Sales_data.

#include "Sales_data.h"
using namespace std;

int main() {
	Sales_data data1 = string("978-7-121-15535-2");
	cout << data1 << endl;
	return 0;
}