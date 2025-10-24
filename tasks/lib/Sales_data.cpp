//���������� 7.12.����������� ����������� ������������ Salesdata(),
//����������� ������ istream, � ���� ������ Sales_data.

//���������� 7.14.�������� ������ ������������ ������������, ����
//���������������� ���������� - ����� ����������, ����������������
//���������������� ����������������.

//���������� 7.26.���������� ������� Salesdata : : avg_price ���
//������������.

//���������� 7.38.������������, ����������� �������� ���� istream&,
//����� ������������ ������ cin ��� �������� �� ���������.��������
//���������� ������������, ������������� ������ cin ��� �������� ��
//���������.

//���������� 7.41.���������� ����������� ������ ������ Sales_data,
//����� ������������ ������������ ������������.�������� � ���� �������
//������������ ��������, ��������� ��������� ������ ���, ����� ��
//�����������.�������� ���������� ��� �������� ������� ������ Sales_data
//������ ���������� ���������.������� ����� � ��������������, ���
//��������� ������� ���������� ������������ �������������.

//���������� 14.2.�������� ���������� ��� ������������� ����������
//�����, ������, �������� � ���������� ���������� ��� ������ Salesdata.


#include <iostream>
#include "Sales_data.h"

double
Sales_data::avg_price() const {
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

Sales_data::Sales_data(const string& s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p* n) {}

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
	Sales_data& result = *this;
	result.units_sold += other.units_sold;
	result.revenue += other.revenue;
	return result;
}
Sales_data& Sales_data::operator +=(const Sales_data& other) {
	units_sold += other.units_sold;
	revenue += other.revenue;
	return *this;
}

Sales_data& Sales_data::operator =(const string& isbn) {
	bookNo = isbn;
	return *this;
}