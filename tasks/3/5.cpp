//Упражнение 3.5.Напишите программу, читающую строки со стандартного
//устройства ввода и суммирующую их в одну большую строку.Отобразите
//полученную строку.Затем измените программу так, чтобы отделять
//соседние введенные строки пробелами.

#include <iostream>
#include <string>
using namespace std;

int main() {
	string line, total, totaWithSpaces;
	cout << "Enter words of text (CTRL+Z for stop):\n";
	while (cin >> line) {
		total += line;
		if (!totaWithSpaces.empty()) {
			totaWithSpaces += " ";
		}
		totaWithSpaces += line + " ";
	}
	cout << "Total string:\n" << total << endl;
	cout << "Total string with spaces:\n" << totaWithSpaces << endl;
	return 0;
}