//Упражнение 16.64.Напишите специализированную версию шаблона из
//предыдущего упражнения для обработки вектора vector<const char*>
//и используйте ее в программе.

#include <vector>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

template <typename T, typename U>
size_t count_elem_vec(const vector<T>& v, const U& elem) {
	size_t count = 0;
	for (const auto& e : v) {
		if (e == elem) {
			++count;
		}
	}
	return count;
}

template<>
size_t count_elem_vec(const vector<const char*>& v, const char* const& elem) {
	size_t count = 0;
	for (const auto& e : v) {
		if (!strcmp(e, elem)) {
			++count;
		}
	}
	return count;
}

int main() {
	vector<const char*> v1 = {"Hello", "world", "Hello"};
	const char* s = "Hello";
	cout << "Count elem string vec: " << count_elem_vec(v1, s) << endl;
	return 0;
}