//���������� 4.31.��������� ����� ������� ������������ ����������
//��������� ���������� � ����������.���������, ������ ����
//������������ ����������, � �� ����������� ������ ? ��� ������� �������� ���
//������������� ����������� ������ ? ���������� ��������� �
//�������������� ����������� ����������.

#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> ivec(10);
	size_t cnt = ivec.size();
	for (size_t ix = 0; ix != ivec.size(); ++ix, --cnt) {
		ivec[ix] = static_cast<int>(cnt);
	}
	for (auto i : ivec) {
		cout << i << " ";
	}
	return 0;
}