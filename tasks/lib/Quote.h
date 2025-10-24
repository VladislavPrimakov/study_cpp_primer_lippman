#ifndef QUOTE_H
#define QUOTE_H

#include <iostream>
#include <string>
using namespace std;


class Quote {
public:
	Quote() = default;
	Quote(const string& book, double sales_price) : bookNo(book), price(sales_price) {}
	string isbn() const {
		return bookNo;
	}
	virtual double net_price(size_t n) const {
		return n * price;
	}
	virtual ~Quote() = default;
	virtual string debug() const {
		return "bookNo: " + bookNo + " price: " + to_string(price);
	}
private:
	string bookNo;
protected:
	double price = 0.0;
};

double print_total(ostream&, const Quote&, size_t);

class Disc_quote : public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const string& book, double price, size_t qty, double disc) : Quote(book, price), quantity(qty), discount(disc) {}
	double net_price(size_t) const = 0;
protected:
	size_t quantity = 0;
	double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const string& book, double p, size_t qty, double disc) : Disc_quote(book, p, qty, disc) {}
	double net_price(size_t) const override;
	virtual string debug() const override {
		return Quote::debug() + " min_qty: " + to_string(quantity) + " discount: " + to_string(discount);
	}
};

class Limit_quote : public Disc_quote {
public:
	Limit_quote() = default;
	Limit_quote(const string& book, double p, size_t qty, double disc) : Disc_quote(book, p, qty, disc) {}
	double net_price(size_t) const override;
};

#endif