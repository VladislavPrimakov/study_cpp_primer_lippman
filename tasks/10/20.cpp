//���������� 10.20.���������� ���������� �������� countif().�������
//��������� findif(), �� �������� ���� ����������, ������������
//�������� �������� � ��������, ����������� � ������� �������� ���������
//���������.������� countif() ���������� ���������� ���, �����
//�������� ������ �������� true.����������� �������� countif(), �����
//���������� �� ����� ���������, ������� ������������ ���������� ���� ������
//������ 6.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	vector<string> words = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
	int sz = 4;
	auto count = count_if(words.begin(), words.end(), [&sz](const string& s) { return s.size() > sz; });
	cout << count << endl;
	return 0;
}