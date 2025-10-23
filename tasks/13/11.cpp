//Упражнение 13.11.Добавьте деструктор в класс HasPtr из предыдущих
//упражнений.

#include <string>
#include <iostream>
using namespace std;

class HasPtr {
public:
	HasPtr(const string& s = string()) : ps(new string(s)), i(0) {}
	HasPtr(const HasPtr& hp) : ps(new string(*hp.ps)), i(hp.i) {}
	HasPtr& operator=(const HasPtr& hp) {
		if (this != &hp) {
			string* new_ps = new string(*hp.ps);
			delete ps;
			ps = new_ps;
			i = hp.i;
		}
		return *this;
	}
	~HasPtr() {
		cout << "Destructor called for string: " << ps << endl;
		delete ps;
	}
	string* ps;
	int i;
};

int main() {
	HasPtr hp1("example");
	HasPtr hp2;
	hp2 = hp1;
	cout << *hp2.ps << " " << hp2.i << endl;
	return 0;
}