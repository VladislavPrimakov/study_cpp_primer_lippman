//”пражнение 12.26.ѕерепишите программу на стр. 613, использу€ класс
//allocator.

#include <iostream>
#include <string>
#include <memory>
using namespace std;

int main() {
	int n = 10;
	allocator<string> alloc;
	string* const p = alloc.allocate(n);
	string s;
	string* q = p;
	cout << "Enter up to " << n << " strings:\n";
	while (cin >> s && q != p + n) {
		new (q++) string(s);
	}
	const size_t size = q - p;
	while (--q >= p)
		q->~string();
	alloc.deallocate(p, n);
	return 0;
}
