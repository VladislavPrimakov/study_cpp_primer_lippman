//”пражнение 16.16.ѕерепишите класс StrVec(см.раздел 13.5, стр. 666), как
//шаблон Vec.

#include "Vec.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
	Vec<string> v1 = {"hello", ",", "world"};
	Vec<int> v2 = {1, 2, 3};
	cout << "Vec v1: " << v1 << endl;
	cout << "Vec v2: " << v2 << endl;
	return 0;
}