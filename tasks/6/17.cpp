//���������� 6.17.�������� �������, ������������, �������� ��
//������ ����� - ������ ��������� �����.�������� �������, ����������� ���
//������ � ������ �������.�������������� � ���� �������� ���������
//����� ��� �� ��� ? ���� ��, �� ������ ? ���� ���, �� ���� ������ ?

#include <cctype>
#include <cctype>
#include <cctype>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;

bool has_uppercase(const string& str) {
	for (char ch : str) {
		if (isupper(ch)) {
			return true;
		}
	}
	return false;
}

void to_lowercase(string& str) {
	for (char& ch : str) {
		ch = tolower(ch);
	}
}


int main() {
	string s;
	cout << "Enter a string: ";
	getline(cin, s);
	if (has_uppercase(s)) {
		cout << "The string contains uppercase letters." << endl;
	} else {
		cout << "The string does not contain uppercase letters." << endl;
	}
	to_lowercase(s);
	cout << "String in lowercase: " << s << endl;
	return 0;
}