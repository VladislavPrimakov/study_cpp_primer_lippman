//Упражнение 7.27.Добавьте функции move(), set() и display() в свою
//версию класса Screen.Проверьте свой класс, выполнив следующий код :

#include <iostream>
#include <Screen.h>

int main() {
	Screen myScreen(5, 5, 'X');
	myScreen.move(4, 0).set('#').display(cout);
	cout << "\n";
	myScreen.display(cout);
	cout << "\n";
	return 0;
}