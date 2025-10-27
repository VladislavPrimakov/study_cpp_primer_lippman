//Упражнение 16.51.Определите, что возвратят операторы
//sizeof. . . (Args) и sizeof. . . (rest) для каждого вызова функции fоо()
//в этом разделе.

#include <iostream>
#include <string>
#include <algorithm>
#include <typeinfo>
using namespace std;

template<typename ... Args> void foo(Args ... args) {
	cout << "Template ... " << sizeof...(Args) << ":" << endl;
	((cout << typeid(Args).name() << endl), ...);
	cout << "Function ... " << sizeof... (args) << ":" << endl;
	((cout << args << endl), ...);
	cout << endl;
}

int main() {
	int i = 0; double d = 3.14; string s = "how now brown cow";
	foo(i, s, 42, d);
	foo(s, 42, "hi");
	foo(d, s);
	foo("hi");
	return 0;
}