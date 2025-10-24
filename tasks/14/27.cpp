//Упражнение 14.27.Добавьте в класс StrBlobPtr операторы инкремента
//и декремента.

#include "StrBlob.h"
using namespace std;

int main() {
	StrBlob sb = {"Hello", "World", "from", "StrBlobPtr"};
	StrBlobPtr sbp(sb);
	cout << sbp << endl;
	sbp++;
	cout << sbp << endl;
	++sbp;
	cout << sbp << endl;
	sbp--;
	cout << sbp << endl;
	--sbp;
	cout << sbp << endl;
	return 0;
}