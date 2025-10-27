//Упражнение 16.58.Напишите функцию emplaceback() для собственного
//класса StrVec и для класса Vec, написанного в упражнении раздела 16.1.2
//(стр. 841).

#include "Vec.h"
#include <string>
using namespace std;

int main() {
	Vec<string> v;
	v.emplace_back("Hello");
	v.emplace_back(5, '!');
	v.emplace_back(string("World"));
	v.emplace_back("C++", 2);
	cout << v << endl;
	return 0;
}