//���������� 12.24.�������� ���������, ������� ������ ������ ��
//������������ ���������� ����� � ����������� ��������� ���������� ������.
//���������, ��� ��������� ������������ ���� ������ ����������� �������.
//��������� ���� ���������, ����� ������, ������ ������� ���������
//����� ������������������ �������.


#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	char* buffer = new char[10];
	int i = 0, c;
	cout << "Enter a string (end with EOF): ";
	while ((c = getchar()) != EOF) {
		buffer[i++] = c;
	}
	buffer[i] = '\0';
	cout << "You entered: ";
	for (int j = 0; j < i; ++j) {
		cout << buffer[j];
	}

	delete[] buffer;
	return 0;
}