//���������� 3.4.�������� ���������, �������� ��� ������ �
//����������, ����� �� ���.� ��������� ������ ��������� ��������, �������
//�� ��� ������.����� �������� ��������� ���, ����� ��� ��������,
//���������� �� � ����� �����, � � ��������� ������ � ������� �� ��� �������.


#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1, s2;
	cout << "Enter two strings:\n";
	getline(cin, s1);
	getline(cin, s2);
	if (s1 == s2)
		cout << "The strings are equal.\n";
	else if (s1 > s2)
		cout << "The first string is greater than the second.\n";
	else
		cout << "The second string is greater than the first.\n";
	if (s1.size() == s2.size()) {
		cout << "The strings have the same lengths.\n";
	} else if (s1.size() > s2.size()) {
		cout << "The first string is longer than the second.\n";
	} else {
		cout << "The second string is longer than the first.\n";
	}


	return 0;
}