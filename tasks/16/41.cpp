//Упражнение 16.41.Напишите версию функции sum() с типом
//возвращаемого значения, который будет гарантированно большим, чтобы содержать
//результат сложения.

#include <iostream>
#include <typeinfo>
using namespace std;

template <typename T, typename U>
auto sum(T a, U b) -> decltype(a + b) {
	return a + b;
}

int main() {
	int i = 1;
	unsigned u = 2;
	long l = 3;
	float f = 4.5f;
	double d = 6.7;
	long long ll = 10000000000LL;

	// Examples
	auto res1 = sum(i, l);   // int + long -> long
	auto res2 = sum(u, i);   // unsigned int + int -> unsigned int (usually)
	auto res3 = sum(i, d);   // int + double -> double
	auto res4 = sum(f, ll);  // float + long long -> double (usually, float promotes to double)
	auto res5 = sum(ll, u); // long long + unsigned int -> long long (usually)

	cout << "sum(int, long): " << res1 << " (Type: " << typeid(res1).name() << ")" << endl;
	cout << "sum(unsigned, int): " << res2 << " (Type: " << typeid(res2).name() << ")" << endl;
	cout << "sum(int, double): " << res3 << " (Type: " << typeid(res3).name() << ")" << endl;
	cout << "sum(float, long long): " << res4 << " (Type: " << typeid(res4).name() << ")" << endl;
	cout << "sum(long long, unsigned): " << res5 << " (Type: " << typeid(res5).name() << ")" << endl;

	return 0;
}