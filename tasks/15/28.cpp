//Упражнение 15.28.Определите вектор для содержания объектов класса Quote,
//но поместите в него объекты класса Bulkquote.Вычислите общую сумму
//результатов вызова функции netprice() для всех элементов вектора.

#include "Quote.h"
#include <vector>
#include <memory>
#include <algorithm>
#include <numeric>
#include <cassert>
using namespace std;

int main() {
	Basket basket;
	basket.add_item(make_shared<Bulk_quote>("12345", 50.0, 10, 0.2));
	basket.add_item(make_shared<Bulk_quote>("67890", 30.0, 15, 0.1));
	basket.add_item(make_shared<Limit_quote>("54321", 20.0, 10, 0.25));
	size_t quantity = 12;
	double sum = accumulate(basket.begin(), basket.end(), 0.0, [quantity](double total, const shared_ptr<Quote>& item) {return total + item->net_price(quantity); });
	assert(sum == (50.0 * 12 * 0.8 + 30.0 * 12 + 20.0 * 10 * 0.75 + 20.0 * 2));
	cout << "Total price for all items in the basket: " << sum << endl;
	return 0;
}