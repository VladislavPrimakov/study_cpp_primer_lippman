//���������� 3.5.�������� ���������, �������� ������ �� ������������
//���������� ����� � ����������� �� � ���� ������� ������.����������
//���������� ������.����� �������� ��������� ���, ����� ��������
//�������� ��������� ������ ���������.

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