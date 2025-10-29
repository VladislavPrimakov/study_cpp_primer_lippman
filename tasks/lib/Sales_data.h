#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>
using namespace std;

template <class T> struct std::hash;

class Sales_data {
	friend struct std::hash<Sales_data>;
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend ostream& print(ostream&, const Sales_data&);
	friend istream& read(istream&, Sales_data&);
	friend istream& operator >>(istream&, Sales_data&);
	friend ostream& operator <<(ostream&, const Sales_data&);
	friend bool operator ==(const Sales_data&, const Sales_data&);
	friend bool operator <(const Sales_data&, const Sales_data&);
public:
	Sales_data(const string&, size_t, double);
	Sales_data() : Sales_data({}, {}, {}) {};
	Sales_data(const string&);
	Sales_data(istream&);
	string isbn() const;
	Sales_data& combine(const Sales_data&);
	inline double avg_price() const;
	Sales_data operator +(const Sales_data&);
	Sales_data& operator +=(const Sales_data&);
	Sales_data& operator =(const string&);
private:
	string bookNo;
	size_t units_sold = 0;
	double revenue = 0.0;
};

class out_of_stock : public runtime_error {
public:
	explicit out_of_stock(const string& s) : runtime_error(s) {}
};

class isbn_mismatch : public logic_error {
public:
	explicit isbn_mismatch(const string& s) : logic_error(s) {}
	isbn_mismatch(const string& s, const string& lhs, const string& rhs) : logic_error(s), left(lhs), right(rhs) {}
	const string left, right;
	const char* what() const noexcept override {
		static string msg_buffer;
		msg_buffer = logic_error::what();
		msg_buffer += " (Left ISBN: " + left + ", Right ISBN: " + right + ")";
		return msg_buffer.c_str();
	}
};

namespace std {
	template<>
	struct hash<Sales_data> {
		typedef size_t result_type;
		typedef Sales_data argument_type;
		size_t operator()(const Sales_data& s) const {
			return hash<string>()(s.bookNo) ^ hash<size_t>()(s.units_sold) ^ hash<double>()(s.revenue);
		}
	};
}

double Sales_data::avg_price() const {
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

Sales_data& Sales_data::combine(const Sales_data& rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

istream& read(istream& is, Sales_data& item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	if (is) {
		item.revenue = price * item.units_sold;
	} else {
		item = Sales_data();
	}
	return is;
}

ostream& print(ostream& os, const Sales_data& item) {
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price();
	return os;
}

Sales_data::Sales_data(const string& s, size_t n, double p) : bookNo(s), units_sold(n), revenue(p* n) {}

Sales_data::Sales_data(const string& s) : Sales_data(s, {}, {}) {}

Sales_data::Sales_data(istream& is) : Sales_data() {
	read(is, *this);
}

string Sales_data::isbn() const {
	return bookNo;
}

inline bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs) {
	return lhs.isbn() < rhs.isbn();
}

istream& operator >>(istream& is, Sales_data& item) {
	return read(is, item);
}

ostream& operator <<(ostream& os, const Sales_data& item) {
	return print(os, item);
}

Sales_data Sales_data::operator +(const Sales_data& other) {
	if (other.bookNo != bookNo) {
		throw isbn_mismatch("ISBNs do not match in += operator", bookNo, other.bookNo);
	}
	Sales_data& result = *this;
	result.units_sold += other.units_sold;
	result.revenue += other.revenue;
	return result;
}

Sales_data& Sales_data::operator +=(const Sales_data& other) {
	if (other.bookNo != bookNo) {
		throw isbn_mismatch("ISBNs do not match in += operator", bookNo, other.bookNo);
	}
	units_sold += other.units_sold;
	revenue += other.revenue;
	return *this;
}

Sales_data& Sales_data::operator =(const string& isbn) {
	bookNo = isbn;
	return *this;
}

bool operator ==(const Sales_data& lhs, const Sales_data& rhs) {
	return lhs.bookNo == rhs.bookNo &&
		lhs.units_sold == rhs.units_sold &&
		lhs.revenue == rhs.revenue;

}

bool operator <(const Sales_data& lhs, const Sales_data& rhs) {
	return lhs.bookNo < rhs.bookNo;
}

#endif
