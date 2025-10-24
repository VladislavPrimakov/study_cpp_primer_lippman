//Упражнение 14.42.Используя библиотечные объекты и адаптеры функций,
//определите объекты для :
//(a) Подсчета количеств значений больше 1024
//(b) Поиска первой строки, не равной pooh
//(c) Умножения всех значений на 2

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
using namespace placeholders;

int main() {
	vector<int> values = {512, 2048, 4096, 256, 1025, 1000};
	int countGreaterThan1024 = count_if(values.begin(), values.end(), bind(greater<int>(), _1, 1024));
	cout << "Count of values greater than 1024: " << countGreaterThan1024 << endl;

	vector<string> strings = {"pooh", "tigger", "eeyore", "pooh", "piglet"};
	auto it = find_if(strings.begin(), strings.end(), bind(not_equal_to<string>(), _1, "pooh"));
	if (it != strings.end()) {
		cout << "First string not equal to 'pooh': " << *it << endl;
	} else {
		cout << "All strings are 'pooh'" << endl;
	}

	vector<int> numbers = {1, 2, 3, 4, 5};
	transform(numbers.begin(), numbers.end(), numbers.begin(), bind(multiplies<int>(), _1, 2));
	cout << "Numbers after multiplying by 2: ";
	for (const auto& num : numbers) {
		cout << num << " ";
	}
	cout << endl;
	return 0;
}