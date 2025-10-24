//”пражнение 14.43.»спользу€ библиотечные объекты функций,
//определите, делимо ли переданное значение типа int на некий элемент в контейнере
//целых чисел.

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
using namespace placeholders;

bool isDivisibleByAny(int value, const vector<int>& divisors) {
	return any_of(divisors.begin(), divisors.end(), bind(equal_to<int>(), 0, bind(modulus<int>(), value, _1)));
}

int main() {
	vector<int> divisors = {2, 3, 5, 7};
	int testValue1 = 14;
	int testValue2 = 13;
	cout << testValue1 << " is divisible by any in divisors: "
		<< (isDivisibleByAny(testValue1, divisors) ? "Yes" : "No") << endl;
	cout << testValue2 << " is divisible by any in divisors: "
		<< (isDivisibleByAny(testValue2, divisors) ? "Yes" : "No") << endl;
	return 0;
}