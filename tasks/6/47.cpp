//���������� 6.47.������������ ���������, ���������� � ����������
//������� 6.3.2 (���. 299), ��� �������������� �������� ��� �����������
//����������� ������� ���, ����� ������� ���������� ���������� � ��
//����������.��������, ���������� ������ ������� ��� ������ ������.
//�������������� � ��������� ��������� � ���������� �������� � �
//�����������.

//#define NDEBUG

#include <iostream>
#include <vector>
using namespace std;

void print_vector(const vector<int>& v, size_t index = 0) {
	if (index >= v.size()) return;
	cout << v[index] << " ";
#ifndef NDEBUG
	cout << endl << "Current index: " << index << endl;
#endif // !NDEBUG
	print_vector(v, index + 1);
}


int main() {
	vector<int> v = {1,2,3,4,5,6,7,8,9,10};
	print_vector(v);
	return 0;
}