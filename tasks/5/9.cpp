//���������� 5.9.�������� ���������, ������������ ����� ���������� i f
//��� �������� ���������� ������� ���� � ������, ����������� �� ������ � in.

#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cout << "Enter text: ";
	getline(cin, s);
	int vowels = 0;
	for (char c : s) {
		if (c == 'a' || c == 'A')
			++vowels;
		else if (c == 'e' || c == 'E')
			++vowels;
		else if (c == 'i' || c == 'I')
			++vowels;
		else if (c == 'o' || c == 'O')
			++vowels;
		else if (c == 'u' || c == 'U')
			++vowels;
	}
	cout << "Number of vowels: " << vowels << endl;
	return 0;
}