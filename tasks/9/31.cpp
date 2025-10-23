//Упражнение 9.31.Программа на стр.455, удаляющая четные и
//дублирующая нечетные элементы, не будет работать с контейнером list или
//forwardlist.Почему ? Переделайте программу так, чтобы она работала
//и с этими типами тоже.

#include <iostream>
#include <forward_list>
using namespace std;

int main() {
	forward_list<int> fl = {0,1,2,3,4,5,6,7,8,9};
	auto iter_curr = fl.begin();
	auto iter_prev = fl.before_begin();
	while (iter_curr != fl.end()) {
		if (*iter_curr % 2) {
			iter_curr = fl.insert_after(iter_curr, *iter_curr);
			iter_prev = iter_curr;
			++iter_curr;
		} else {
			iter_curr = fl.erase_after(iter_prev);
		}
	}
	for (const auto& i : fl) {
		cout << i << " ";
	}
	return 0;
}