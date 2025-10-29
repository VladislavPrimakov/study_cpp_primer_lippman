#ifndef QUOTE_H
#define QUOTE_H

#include <iostream>
#include <string>
#include <set>
using namespace std;


class Quote {
public:
	Quote() = default;
	Quote(const Quote&) = default;
	Quote(Quote&&) = default;
	Quote& operator=(const Quote&) = default;
	Quote& operator=(Quote&&) = default;
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
	virtual Quote* clone() const& {
		return new Quote(*this);
	}
	virtual Quote* clone()&& {
		return new Quote(move(*this));
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
	pair<size_t, double> discount_policy() const {
		return {quantity, discount};
	}
	virtual string debug() const override {
		return Quote::debug() + " quantity: " + to_string(quantity) + " discount: " + to_string(discount);
	}
protected:
	size_t quantity = 0;
	double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const Bulk_quote&) = default;
	Bulk_quote(Bulk_quote&&) = default;
	Bulk_quote(const string& book, double p, size_t qty, double disc) : Disc_quote(book, p, qty, disc) {}
	double net_price(size_t) const override;
	Bulk_quote* clone() const& override {
		return new Bulk_quote(*this);
	}
	Bulk_quote* clone() && override {
		return new Bulk_quote(move(*this));
	}
};

class Limit_quote : public Disc_quote {
public:
	Limit_quote() = default;
	Limit_quote(const Limit_quote&) = default;
	Limit_quote(Limit_quote&&) = default;
	Limit_quote(const string& book, double p, size_t qty, double disc) : Disc_quote(book, p, qty, disc) {}
	double net_price(size_t) const override;

	Limit_quote* clone() const& override {
		return new Limit_quote(*this);
	}
	Limit_quote* clone() && override {
		return new Limit_quote(move(*this));
	}
};


class Basket {
	static bool compare(const shared_ptr<Quote>& lhs, const shared_ptr<Quote>& rhs) {
		return lhs->isbn() < rhs->isbn();
	}
	multiset<shared_ptr<Quote>, decltype(compare)*> items {compare};
public:
	void add_item(const shared_ptr<Quote>& sale) {
		items.insert(sale);
	}
	void add_item(const Quote& sale) {
		items.insert(shared_ptr<Quote>(sale.clone()));
	}
	void add_item(Quote&& sale) {
		items.insert(shared_ptr<Quote>(move(sale).clone()));
	}
	double total_receipt(ostream& os) const {
		double sum = 0.0;
		for (auto iter = items.cbegin(); iter != items.cend();) {
			auto next_iter = items.upper_bound(*iter);
			sum += print_total(os, **iter, distance(iter, next_iter));
			iter = next_iter;
		}
		os << "Total Sale: " << sum << endl;
		return sum;
	}
	auto begin() {
		return items.begin();
	}
	auto end() {
		return items.end();
	}
};


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


#endif