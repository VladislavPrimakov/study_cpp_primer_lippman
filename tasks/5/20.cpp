//���������� 5.20.�������� ���������, ������� ������
//������������������ ����� �� ������������ ���������� ����� �� ��� ���, ���� �� ����������
//������������� ����� ��� ���� ���� ���� �� ����� ��������.��� ������
//������ �� ������ ����� ����������� ���� while.��� ������ �� ����� ���
//������� ���� ����������� ���� ������ ����������� �������� break.
//�������� ������������� �����, ���� ��� ����, � � ��������� ������ ����������
//���������, ����������������� � ���, ��� ������������� ���� ���.

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