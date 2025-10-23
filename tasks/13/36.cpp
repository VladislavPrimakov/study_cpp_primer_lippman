//Упражнение 13.36.Разработайте и реализуйте соответствующий класс
//Folder.Этот класс должен содержать набор указателей на сообщения в той
//папке.

#include "Message.h"
using namespace std;

int main() {
	Message msg1("Hello, World!");
	Folder folder1("Work");
	Folder folder2;
	msg1.save(folder1);
	folder2 = folder1;
	cout << msg1 << endl;

	Message msg2("C++ Programming");
	msg2.save(folder1);
	cout << msg2 << endl;

	Message msg3(msg1);
	msg3.remove(folder1);
	msg3.remove(folder2);
	cout << msg1 << endl;
	cout << msg3 << endl;


	return 0;
}