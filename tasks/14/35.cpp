//Упражнение 14.35.Напишите класс, подобный классу PrintString,
//который читает строку из потока istream и возвращает строку,
//представляющую прочитанное.При неудаче чтения следует возвратить пустую строку.

#include <iostream>
#include <string>
using namespace std;

class ReadString {
public:
	string operator()(istream& is) {
		string result;
		if (getline(is, result)) {
			return result;
		} else {
			return "";
		}
	}
};

int main() {
	ReadString readStr;
	cout << "Please enter a string: ";
	string input = readStr(cin);
	cout << "You entered: " << input << endl;
	return 0;
}