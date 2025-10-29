#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
	string address;
public:
	string get_name() const {
		return name;
	}
	string get_address() const {
		return address;
	}
	Person() = default;
	Person(const string& n, const string& a) : name(n), address(a) {}
	friend istream& read(istream&, Person&);
	friend ostream& print(ostream&, const Person&);
};

istream& read(istream& is, Person& p) {
	is >> p.name >> p.address;
	return is;
}

ostream& print(ostream& os, const Person& p) {
	os << p.get_name() << " " << p.get_address();
	return os;
}

#endif // !PERSON_H