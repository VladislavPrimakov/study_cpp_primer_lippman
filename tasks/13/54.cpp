//”пражнение 13.54.„то бы случилось, если бы мы определи оператор
//присваивани€ при перемещении дл€ класса HasPtr, но не изменили оператор
//копии и обмена ? Ќапишите код дл€ проверки вашего ответа.


#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;

class HasPtr {
public:
	HasPtr(const string& s = string()) : ps(new string(s)), i(0) {}
	HasPtr(const HasPtr& other) : ps(new string(*other.ps)), i(other.i) {}
	HasPtr& operator=(HasPtr hp) {
		swap(*this, hp);
		return *this;
	}
	// need to work faster
	HasPtr(HasPtr&& other) noexcept : ps(other.ps), i(other.i) {
		other.ps = nullptr;
	}
	// HasPtr& operator=(HasPtr&& other) is ambiguous
	//HasPtr& operator=(HasPtr&& other) noexcept {
	//	if (this != &other) {
	//		delete ps;
	//		ps = other.ps;
	//		i = other.i;
	//		other.ps = nullptr;
	//	}
	//	return *this;
	//}
	~HasPtr() {
		delete ps;
	}
	friend void swap(HasPtr& lhs, HasPtr& rhs);
	string* ps;
	int i;
};

void swap(HasPtr& lhs, HasPtr& rhs) {
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}


inline uint64_t rdtsc_msvc() {
	return __rdtsc();
}

int main() {
	size_t N = 1000000;
	auto start = rdtsc_msvc();
	for (size_t i = 0; i < N; ++i) {
		HasPtr hp1("Hello World!");
		HasPtr hp2("Hello World!");
		hp1 = hp2;
	}
	auto end = rdtsc_msvc();
	cout << "Copy assignment cycles: " << (end - start) / N << endl;

	start = rdtsc_msvc();
	for (size_t i = 0; i < N; ++i) {
		HasPtr hp1("Hello World!");
		HasPtr hp2("Hello World!");
		hp1 = move(hp2);
	}

	end = rdtsc_msvc();
	cout << "Move assignment cycles: " << (end - start) / N << endl;
	return 0;
}