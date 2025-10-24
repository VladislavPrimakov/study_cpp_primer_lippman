//”пражнение 13.27.ќпределите собственную версию класса HasPtr со
//счетчиком ссылок.

#include <string>
#include <iostream>
using namespace std;

class HasPtr {
public:
	HasPtr(const string& s = string()) : ps(new string(s)), i(0), ref_count(new size_t(1)) {}
	HasPtr(const HasPtr& other) : ps(other.ps), i(other.i), ref_count(other.ref_count) {
		++*ref_count;
	}
	HasPtr& operator=(HasPtr hp) {
		swap(*this, hp);
		return *this;
	}
	~HasPtr() {
		cout << "Deleting: " << *ps << " Ref count: " << *ref_count - 1 << endl;
		if (--*ref_count == 0) {
			delete ps;
			delete ref_count;
		}
	}
	string* ps;
	size_t* ref_count;
	int i;
};

int main() {
	HasPtr hp1("hp1");
	cout << *hp1.ps << " Ref count: " << *hp1.ref_count << endl;

	HasPtr hp2(hp1);
	cout << *hp1.ps << " Ref count: " << *hp1.ref_count << endl;

	HasPtr hp3;
	hp3 = hp2;

	cout << *hp1.ps << " Ref count: " << *hp1.ref_count << endl;
	return 0;
}