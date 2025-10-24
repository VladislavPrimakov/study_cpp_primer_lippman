//Упражнение 15.13.С учетом следующих классов объясните каждую из
//функций print().Если в этом коде имеются ошибки, устраните их.

#include <iostream>
#include <string>
using namespace std;

class base {
public:
	string name() {
		return basename;
	}
	virtual void print(ostream& os) {
		os << basename;
	}
private:
	string basename;
};

class derived : public base {
public:
	void print(ostream& os) {
		// added base
		base::print(os);
		os << " " << i;
	}
private:
	int i = 0;
};


int main() {
	derived d;
	d.print(cout);
	return 0;
}