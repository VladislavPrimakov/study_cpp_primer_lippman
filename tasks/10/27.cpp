//���������� 10.27.� ���������� � ������� unique() (��.������ 10.2.3, ���.492) ���������� ���������� ������� uniquecopy(), ����������
//	������ ��������, ������������ ���������� ����������� ����������
//	���������.�������� ���������, ������� ���������� �������
//	uniquecopy() ��� ����������� ���������� ��������� ������� �
//	������������� ������ ������.

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
	vector<int> v = {1,2,3,4,5,6,7,8,9,2,3,4};
	vector<int> c;
	sort(v.begin(), v.end());
	unique_copy(v.begin(), v.end(), back_inserter(c));
	for_each(c.begin(), c.end(), [](int& i) {cout << i << " "; });
	return 0;
}