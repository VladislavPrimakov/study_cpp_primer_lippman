//���������� 3.43.�������� ��� ������ ������ ��������� ��� ������
//��������� ������� ia.���� ������ ������ ������������ ��� ����������
//��������� �������� �������� for, � ������ ��� ������� ���� for, ��
//� ����� ������ ������������ ��������������, � � ������ � ���������.
//�� ���� ���� ���������� ������ ��� ���� ����, �.�.�� �����������
//���������� ����� � ������������� auto ��� decltype ��� ��������� ����.


#include <iostream>
using namespace std;

int main() {
	int ia[3][3] = {{1,2,3},
					{4,5,6},
					{7,8,9}};
	cout << "Using range-based for loop:" << endl;
	for (int(&row)[3] : ia) {
		for (int& elem : row) {
			cout << elem << " ";
		}
		cout << endl;
	}
	cout << "Using for loop with indexing:" << endl;
	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0; j < 3; ++j) {
			cout << ia[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Using for loop with pointers:" << endl;
	for (int (*p)[3] = ia; p != ia + 3; ++p) {
		for (int* q = *p; q != *p + 3; ++q) {
			cout << *q << " ";
		}
		cout << endl;
	}

	return 0;
}