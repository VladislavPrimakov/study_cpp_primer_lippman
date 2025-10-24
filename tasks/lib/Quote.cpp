#include "Quote.h"
#include <ostream>

double print_total(ostream& os, const Quote& item, size_t n) {
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
	return ret;
}

double Bulk_quote::net_price(size_t cnt) const {
	if (cnt >= quantity)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}

double Limit_quote::net_price(size_t cnt) const {
	size_t diff = cnt > quantity ? cnt - quantity : 0;
	double sum = diff * price;
	sum += (cnt - diff) * (1 - discount) * price;
	return sum;
}
