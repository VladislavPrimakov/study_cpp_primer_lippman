//”пражнение 14.23.ќпределите в версии класса StrVec оператор
//присвоени€ дл€ типа initializer_list.

#include "StrVec.h"
#include <iostream>
using namespace std;

int main() {
	StrVec sv;
	sv = {"This", "is", "a", "test"};
	cout << sv << endl;
	return 0;
}