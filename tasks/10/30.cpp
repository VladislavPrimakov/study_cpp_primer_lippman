//���������� 10.30.����������� ��������� ���������, � ����� �������
//sort() � ����() ��� ������ ������������������ ����� ����� ��
//������������ ���������� �����, �� ���������� � ������������ ������ ��
//����������� ���������� ������.

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	istream_iterator<int> ii(cin), eof;
	vector<int> vec(ii, eof);
	sort(vec.begin(), vec.end());
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
	return 0;
}