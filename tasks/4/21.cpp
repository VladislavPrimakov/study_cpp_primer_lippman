//���������� 4.21.�������� ���������, ������������ ��������
//�������� ��� ������ � ������� vector<int> ��������� � �������� ���������
//� �� ��������.

#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	for (auto& i : vec) {
		cout << (i % 2 == 1 ? i * 2 : i) << " ";
	}
	cout << endl;
	return 0;
}