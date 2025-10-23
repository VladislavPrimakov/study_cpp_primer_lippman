//Упражнение 9.11.Приведите пример каждого из шести способов создания
//и инициализации контейнеров vector.Объясните, какие значения будет
//содержать каждый вектор.

#include <iostream>
#include <vector>
using namespace std;

void print_vector(const vector<int>& vec) {
	for (const auto& val : vec) {
		cout << val << " ";
	}
	cout << endl;
}

int main() {
	vector<int> vec1;
	cout << "vec1 (default constructor): ";
	print_vector(vec1);

	vector<int> vec2(5);
	cout << "vec2 (size constructor): ";
	print_vector(vec2);

	vector<int> vec3(5, 10);
	cout << "vec3 (size and value constructor): ";
	print_vector(vec3);

	vector<int> vec4 {1, 2, 3, 4, 5};
	cout << "vec4 (initializer list constructor): ";
	print_vector(vec4);

	vector<int> vec5(vec4);
	cout << "vec5 (copy constructor): ";
	print_vector(vec5);

	vector<int> vec6(vec4.begin(), vec4.end());
	cout << "vec6 (range constructor): ";
	print_vector(vec6);

	return 0;
}