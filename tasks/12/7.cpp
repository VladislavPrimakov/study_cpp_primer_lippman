//”пражнение 12.7.ѕеределайте предыдущее упражнение, использу€ на сей
//раз указатель sharedptr.

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

shared_ptr<vector<int>> createVector() {
	return make_shared<vector<int>>();
}

void readValues(shared_ptr<vector<int>> vec) {
	int value;
	cout << "Enter integers (CTRL+Z to end):" << endl;
	while (cin >> value) {
		vec->push_back(value);
	}
}

void printValues(const shared_ptr<vector<int>> vec) {
	cout << "You entered:" << endl;
	for (const int& val : *vec) {
		cout << val << " ";
	}
	cout << endl;
}

int main() {
	auto v = createVector();
	readValues(v);
	printValues(v);
	v.~shared_ptr();
	printValues(v);
	return 0;
}