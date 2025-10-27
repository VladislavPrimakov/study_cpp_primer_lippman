//Упражнение 16.62.Определите собственную версию класса hash<Sales_
//	data> и контейнер unordered_multiset объектов класса Sales_data.
//	Поместите в контейнер несколько транзакций и выведите его содержимое.

#include "Sales_data.h"
#include <unordered_set>
#include <iostream>
using namespace std;

int main() {
	unordered_multiset<Sales_data> sales_set;
	sales_set.insert(Sales_data("12345", 10, 20.0));
	sales_set.insert(Sales_data("12345", 5, 20.0));
	sales_set.insert(Sales_data("67890", 8, 15.0));
	for (const auto& sale : sales_set) {
		cout << sale << endl;
	}
	return 0;
}