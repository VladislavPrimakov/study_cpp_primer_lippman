//Упражнение 8.1.Напишите функцию, получающую и возвращающую
//ссылку на объект класса istream.Функция должна читать данные из потока до
//тех пор, пока не будет достигнут конец файла.Функция должна выводить
//прочитанные данные на стандартное устройство вывода.Перед
//возвращением потока верните все значения его флагов в допустимое состояние.

#include <iostream>
#include <string>
using namespace std;

istream& func(istream& is) {
	string line;
	while (getline(is, line)) {
		cout << line << endl;
	}
	is.clear();
	return is;
}


int main() {
	func(cin);
	return 0;
}
