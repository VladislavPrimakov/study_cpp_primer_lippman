//Упражнение 16.24.Добавьте в свой шаблон Blob конструктор,
//получающий два итератора.

#include "Blob.h"
#include <vector>
#include <list>
using namespace std;

int main() {
	int ia[] = {0,1,2,3,4,5,6,7,8,9};
	vector<long> vi = {0,1,2,3,4,5,6,7,8,9};
	list<const char*> w = {"now", "is", "the", "time"};
	Blob<int> al(begin(ia), end(ia));
	cout << al << endl;
	Blob<int> a2(vi.begin(), vi.end());
	cout << a2 << endl;
	Blob<string> a3(w.begin(), w.end());
	cout << a3 << endl;
	return 0;
}