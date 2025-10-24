//Упражнение 13.53.С точки зрения низкоуровневой эффективности
//оператор присвоения класса HasPtr не идеален.Объясните почему.Реализуйте
//для класса HasPtr оператор присвоения копии и присваивания при
//перемещении и сравните действия, выполняемые в новом операторе
//присваивания при перемещении, с версией копии и обмена.

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
	HasPtr& operator=(HasPtr& other) {
		string* new_ps = new string(*other.ps);
		delete ps;
		ps = new_ps;
		i = other.i;
		return *this;
	}
	HasPtr(HasPtr&& other) noexcept : ps(other.ps), i(other.i) {
		other.ps = nullptr;
	}
	HasPtr& operator=(HasPtr&& other) noexcept {
		if (this != &other) {
			delete ps;
			ps = other.ps;
			i = other.i;
			other.ps = nullptr;
		}
		return *this;
	}
	~HasPtr() {
		delete ps;
	}
	string* ps;
	int i;
};

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