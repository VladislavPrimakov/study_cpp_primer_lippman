//���������� 10.1.� ��������� algorithm ���������� ������� count(),
//�������� ������� find �.��� �������� ��� ��������� � ��������, �
//���������� ���������� ������������ � ��������� ���������, ����������
//������� ���������.����������� ������ � ������ ������������������
//����� �����.����������� ������� ��������� � ��������� ���������.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector <int> v = {1,2,3,4,5,6,3,3,2};
	int value = 3;
	cout << "Count of " << value << " is " << count(v.begin(), v.end(), value) << endl;
	return 0;
}