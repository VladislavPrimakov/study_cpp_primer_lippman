#include <iostream>
using namespace std;

class Base {
	friend bool operator== (const Base&, const Base&);
protected:
	virtual bool equal(const Base&) const;
};

bool operator==(const Base& lhs, const Base& rhs) {
	return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
}

bool Base::equal(const Base& rhs) const {
	return true;
}

class Derived : public Base {
protected:
	bool operator==(const Derived& rhs) const {
		return true;
	}
	bool equal(const Base&) const override;
};

bool Derived::equal(const Base& rhs) const {
	auto r = dynamic_cast<const Derived&> (rhs);
	return *this == r;
}


int main() {
	Base* b1 = new Base();
	Base* b2 = new Derived();
	Base* b3 = new Derived();
	cout << "*Base(Base) == *Base(Derived) -> " << (*b1 == *b2) << endl;
	cout << "*Base(Derived) == *Base(Derived) -> " << (*b2 == *b3) << endl;
	return 0;
}