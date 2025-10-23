//Упражнение 4.36.С учетом того, что i имеет тип int, a d — double,
//напишите выражение i *= d так, чтобы осуществлялось целочисленное
//умножение, а не с плавающей запятой.

#include <iostream>
using namespace std;

int main() {
	int i = 3;
	double d = 4.5;
	i *= static_cast<int>(d);
	cout << i << endl;
	return 0;
}