//���������� 17.2.���������� ������, ���������� ������, ������
//������ � ���� �� ������ � ������ �����(���� string, vector<string>
//									   � pair<string, int>).

#include <tuple>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	tuple<string, vector<string>, pair<string, int>> t {"String", {"Vector", "String"}, {"String pair", 10}};
	cout << get<2>(t).first << endl;
	return 0;
}