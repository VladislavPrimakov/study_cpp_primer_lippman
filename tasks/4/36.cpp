//���������� 4.36.� ������ ����, ��� i ����� ��� int, a d � double,
//�������� ��������� i *= d ���, ����� �������������� �������������
//���������, � �� � ��������� �������.

#include <iostream>
using namespace std;

int main() {
	int i = 3;
	double d = 4.5;
	i *= static_cast<int>(d);
	cout << i << endl;
	return 0;
}