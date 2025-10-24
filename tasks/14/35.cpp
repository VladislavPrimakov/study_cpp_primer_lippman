//���������� 14.35.�������� �����, �������� ������ PrintString,
//������� ������ ������ �� ������ istream � ���������� ������,
//�������������� �����������.��� ������� ������ ������� ���������� ������ ������.

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