//���������� 6.54.�������� ���������� �������, ���������� ���
//��������� ���� int, � ������������ ��� int.�������� ����� ������,
//���������� �������� �������� ��� ��������� �� ��� �������.

#include <iostream>
#include <vector>
using namespace std;

int& f(int& a, int& b) {
	return a > b ? a : b;
}

int main() {
	vector<int& (*)(int&, int&)> vec;
	vec.push_back(f);
	for (auto p : vec) {
		int x = 10, y = 20;
		cout << p(x, y) << endl;
	}
	return 0;
}