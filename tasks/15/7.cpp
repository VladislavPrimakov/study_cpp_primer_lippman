//Упражнение 15.7.Определите класс, реализующий ограниченную
//стратегию скидок, которая применяет скидку только к покупкам до заданного
//предела.Если количество экземпляров превышает этот предел, к остальным
//применяется обычная цена.

#include "Quote.h"
#include <cassert>
#include <iostream>
using namespace std;

int main() {
	Quote q("12345", 50.0);
	Bulk_quote bq("67890", 50.0, 10, 0.2); // 20% discount for 10 or more
	Limit_quote lq("54321", 50.0, 5, 0.1); // 10% discount for up to 5
	auto s1 = print_total(cout, q, 3);   // No discount
	assert(s1 == 150.0);
	auto s2 = print_total(cout, bq, 15); // Discount applies
	assert(s2 == 600.0);
	auto s3 = print_total(cout, lq, 7);  // Discount applies only to first 5
	assert(s3 == 325.0);
	return 0;
}