//Упражнение 17.28.Напишите функцию, создающую и возвращающую
//равномерно распределенную последовательность случайных беззнаковых
//целых чисел при каждом вызове.

#include <iostream>
#include <vector>
#include <random>
using namespace std;

vector<unsigned> generate_random_unsigneds(size_t n, unsigned min, unsigned max) {
	static default_random_engine e;
	uniform_int_distribution<unsigned> gen(min, max);
	vector<unsigned> result;
	result.reserve(n);
	for (size_t i = 0; i < n; ++i) {
		result.push_back(gen(e));
	}
	return result;
}

int main() {
	vector<unsigned> random_numbers = generate_random_unsigneds(10, 0, 100);
	for (unsigned num : random_numbers) {
		cout << num << " ";
	}
	cout << endl;
	vector<unsigned> random_numbers2 = generate_random_unsigneds(10, 0, 100);
	for (unsigned num : random_numbers2) {
		cout << num << " ";
	}
	cout << endl;
	return 0;
}