//Упражнение 19.8.Напишите выражение typeid, чтобы убедиться,
//указывают ли два указателя на класс Querybase на тот же тип.Затем проверьте,
//не является ли этот тип классом AndQuery.

#include "TextQuery.h"
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

int main() {
	Query_base* qb1 = new AndQuery(Query("word1"), Query("word2"));
	Query_base* qb2 = new AndQuery(Query("word3"), Query("word4"));

	if (typeid(qb1) == typeid(qb2)) {
		cout << "Both pointers qb1 and qb2 point to the same type." << endl;
	} else {
		cout << "Pointers qb1 and aq2 point to different types." << endl;
	}

	if (typeid(*qb1) == typeid(AndQuery)) {
		cout << "The type pointed to by qb1 is AndQuery." << endl;
	} else {
		cout << "The type pointed to by qb1 is not AndQuery." << endl;
	}
	return 0;
}