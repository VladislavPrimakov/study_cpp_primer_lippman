//Упражнение 16.19.Напишите функцию, получающую ссылку на контейнер
//и выводящую его элементы.Используйте переменную sizetype и
//функцию - член size() контейнера для контроля цикла, вывода элементов.

#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

template <typename Container>
void printContainer(const Container& cont) {
	typename Container::size_type size = cont.size();
	for (typename Container::size_type i = 0; i < size; ++i) {
		cout << *(next(cont.begin(), i)) << " ";
	}
	cout << endl;
}

int main() {
	vector<int> vec = {1, 2, 3, 4, 5};
	list<string> lst = {"Hello", "World", "from", "C++"};
	cout << "Vector elements: ";
	printContainer(vec);
	cout << "List elements: ";
	printContainer(lst);
	return 0;
}