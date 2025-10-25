//Упражнение 15.39.Реализуйте классы Query и Querybase.Проверьте
//приложение на вычислении и выводе запроса, представленного на рис. 15.3
//(стр. 805).

#include "TextQuery.h"
#include <string>
#include <sstream>
using namespace std;

int main() {
	stringstream ss;
	ss << "Alice Emma has long flowing red hair." << endl;
	ss << "Her Daddy says when the wind blows" << endl;
	ss << "through her hair, it looks almost alive," << endl;
	ss << "like a fiery bird in flight." << endl;
	ss << "A beautiful fiery bird, he tells her," << endl;
	ss << "magical but untamed." << endl;
	ss << "\"Daddy, shush, there is no such thing, \"" << endl;
	ss << "she tells him, at the same time wanting" << endl;
	ss << "him to tell her more." << endl;
	ss << "Shyly, she asks, \"I mean, Daddy, is there ? \"" << endl;
	TextQuery tq(ss);

	Query q = Query("Daddy");
	print(cout, q.eval(tq));

	q = ~Query("Alice");
	print(cout, q.eval(tq));

	q = Query("hair") | Query("Alice");
	print(cout, q.eval(tq));

	q = Query("hair") & Query("Alice");
	print(cout, q.eval(tq));

	q = Query("fiery") & Query("bird") | Query("wind");
	print(cout, q.eval(tq));
	return 0;
}