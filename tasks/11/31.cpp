//Упражнение 11.31.Напишите программу, определяющую контейнер
//multimap авторов и их работ.Используйте функцию find() для поиска
//элемента и его удаления.Убедитесь в корректности работы программы,
//когда искомого элемента нет в карте.

#include <iostream>
#include <map>
#include <string>
using namespace std;

void remove_all(multimap<string, string>& m, string author) {
	auto it = m.find(author);
	if (it != m.end()) {
		auto it_end = it;
		++it_end;
		while (it_end != m.end() && it_end->first == author) {
			++it_end;
		}
		m.erase(it, it_end);
	}
}

void print(multimap<string, string>& m) {
	for (auto& entry : m) {
		cout << entry.first << " : " << entry.second << endl;
	}
}

int main() {
	multimap<string, string> authors_works = {{"Author1", "Work1"}, {"Author2", "Work2"},{"Author2", "Work3"}};
	remove_all(authors_works, "Author3");
	remove_all(authors_works, "Author2");
	print(authors_works);
	return 0;
}