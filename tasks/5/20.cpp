//”пражнение 5.20.Ќапишите программу, котора€ читает
//последовательность строк со стандартного устройства ввода до тех пор, пока не встретитс€
//повтор€ющеес€ слово или пока ввод слов не будет закончен.ƒл€ чтени€
//текста по одному слову используйте цикл while.ƒл€ выхода из цикла при
//встрече двух совпадающих слов подр€д используйте оператор break.
//¬ыведите повтор€ющеес€ слово, если оно есть, а в противном случае отобразите
//сообщение, свидетельствующее о том, что повтор€ющихс€ слов нет.

#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	string prev;
	bool found = false;
	cout << "Enter words (CTRL+Z to end):" << endl;
	while (cin >> s) {
		if (s == prev) {
			cout << "Repeated word: " << s << endl;
			found = true;
			break;
		}
		prev = s;

	}
	if (!found)
		cout << "No repeated words" << endl;
	return 0;
}