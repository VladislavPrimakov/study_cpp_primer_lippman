//���������� 9.18.�������� ��������� ������ ������������������ �����
//�� ������������ ���������� ����� � ��������� deque.��� ������ ���������
//� ��������� deque ����������� ��������� � ����.

#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	deque<string> str_deque;
	string s;
	cout << "Enter strings (CTRL+Z to end):" << endl;
	while (getline(cin, s)) {
		str_deque.insert(str_deque.cbegin(), s);
	}
	cout << "You entered the following strings:" << endl;
	for (const auto& str : str_deque) {
		cout << str << endl;
	}
	return 0;
}