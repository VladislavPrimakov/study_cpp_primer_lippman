#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

using namespace std;

class Sales_data {
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend ostream& print(ostream&, const Sales_data&);
	friend istream& read(istream&, Sales_data&);
	friend istream& operator >>(istream&, Sales_data&);
	friend ostream& operator <<(ostream&, const Sales_data&);
public:
	Sales_data(const string&, unsigned, double);
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
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
ostream& print(ostream&, const Sales_data&);
istream& read(istream&, Sales_data&);
istream& operator >>(istream&, Sales_data&);
ostream& operator <<(ostream&, const Sales_data&);

#endif
