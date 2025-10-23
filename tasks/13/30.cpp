//Упражнение 13.30.Напишите и проверьте функцию swap() для подобной
//значению версии класса HasPtr.Снабдите свою функцию swap()
//оператором вывода примечания о ее выполнении.

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class HasPtr {
public:
	HasPtr(const string& s = string()) : ps(new string(s)), i(0) {}
	HasPtr(const HasPtr& hp) : ps(new string(*hp.ps)), i(hp.i) {}
	HasPtr& operator=(HasPtr hp) {
		swap(*this, hp);
		return *this;
	}
	~HasPtr() {
		cout << "Destructor called: " << ps << " (" << *ps << ")" << endl;
		delete ps;
	}
	friend void swap(HasPtr& lhs, HasPtr& rhs);
	string* ps;
	int i;
};

void swap(HasPtr& lhs, HasPtr& rhs) {
	cout << "Swapping HasPtr objects: " << lhs.ps << " (" << *lhs.ps << ")" << " and " << rhs.ps << " (" << *rhs.ps << ")" << endl;
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}

int main() {
	HasPtr hp1("hp1");
	HasPtr hp2("hp2");
	HasPtr hp3("hp3");
	vector<HasPtr> vec = {hp3, hp2, hp1};
	sort(vec.begin(), vec.end(), [](const HasPtr& a, const HasPtr& b) {return *a.ps < *b.ps; });
	return 0;
}