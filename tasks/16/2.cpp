//Упражнение 16.2.Напишите и проверьте собственные версии функций
//compare().

#include <iostream>
#include <string>
using namespace std;

template <typename T>
int compare(const T& v1, const T& v2) {
	if (v1 < v2)
		return -1;
	if (v2 < v1)
		return 1;
	return 0;
}

int main() {
	cout << compare(10, 20) << endl;
	cout << compare(3.14, 2.71) << endl;
	cout << compare(string("apple"), string("banana")) << endl;
	return 0;
}