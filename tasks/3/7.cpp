//���������� 3.7.��� �����, ���� ���������� ����������� ����������
//����� � ���������� ���������� ��� ������� ��� char ? �����������
//���������, � ����� �������� ��������� ���, ����� ������������� ��� char,
//� ��������� � ����� �������.

#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cout << "Enter a string:\n";
	getline(cin, s);
	for (char& ch : s) {
		ch = 'x';
	}
	cout << "Modified string:\n" << s << endl;
	return 0;
}