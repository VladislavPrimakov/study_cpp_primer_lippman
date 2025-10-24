//Упражнение 15.6.Проверьте свою функцию printtotal() из
//упражнения раздела 15.2.1 (стр.752), передав ей объекты класса Quote и Bulk_
//quote.

#include "Quote.h"
using namespace std;

int main () {
	Quote q("12345", 50.0);
	Bulk_quote bq("67890", 50.0, 10, 0.2);
	print_total(cout, q, 5);
	print_total(cout, bq, 15);
	return 0;
}