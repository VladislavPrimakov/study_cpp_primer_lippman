//Упражнение 9.27.Напишите программу для поиска и удаления нечетных
//элементов в контейнере forward_list<int>.

#include <iostream>
#include <forward_list>
using namespace std;

int main() {
	forward_list<int> fl = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto prev = fl.before_begin();
	auto curr = fl.begin();
	while (curr != fl.end()) {
		if (*curr % 2 != 0) {
			curr = fl.erase_after(prev);
		} else {
			++prev;
			++curr;
		}
	}
	for (const auto& i : fl) {
		cout << i << " ";
	}
	return 0;
}