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

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

class Sales_data {
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::ostream& print(std::ostream&, const Sales_data&);
	friend std::istream& read(std::istream&, Sales_data&);
public:
	Sales_data(const std::string& s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p* n) {}
	Sales_data() : Sales_data({}, {}, {}) {}
	Sales_data(const std::string& s) : Sales_data(s, {}, {}) {}
	Sales_data(std::istream& is) : Sales_data() {
		read(is, *this);
	}
	std::string isbn() const {
		return bookNo;
	}
	Sales_data& combine(const Sales_data&);
	inline double avg_price() const;
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream& print(std::ostream&, const Sales_data&);
std::istream& read(std::istream&, Sales_data&);

inline bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs) {
	return lhs.isbn() < rhs.isbn();
}
#endif
