//���������� 3.31.�������� ���������, ��� ��������� ������ �� ������
//����� �����, ������� �������� �������� ��������� ��������,
//��������������� ��� ������� � �������.

#include <iostream>
using namespace std;

int main() {
	int arr[10];
	for (int i = 0; i < 10; ++i) {
		arr[i] = i;
	}
	for (const auto& e : arr) {
		cout << e << " ";
	}
	return 0;
}