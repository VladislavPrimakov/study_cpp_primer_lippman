//���������� 8.1.�������� �������, ���������� � ������������
//������ �� ������ ������ istream.������� ������ ������ ������ �� ������ ��
//��� ���, ���� �� ����� ��������� ����� �����.������� ������ ��������
//����������� ������ �� ����������� ���������� ������.�����
//������������ ������ ������� ��� �������� ��� ������ � ���������� ���������.

#include <iostream>
#include <string>
using namespace std;

istream& func(istream& is) {
	string line;
	while (getline(is, line)) {
		cout << line << endl;
	}
	is.clear();
	return is;
}


int main() {
	func(cin);
	return 0;
}
