//���������� 13.5.�������� � ������ ���������� ������ ������
//����������� �����, ���������� ��� ���������� - �����.����������� ������
//����������� ������������� ����� ������(��.������ 12.1.2 ���. 584) �
//���������� ������, �� ������� ��������� ps, � �� ��� ��������� ps.

#include <string>
#include <iostream>
using namespace std;

class HasPtr {
public:
	HasPtr(const string& s = string()) : ps(new string(s)), i(0) {}
	HasPtr(const HasPtr& hp) : ps(new string(*hp.ps)), i(hp.i) {}
	string* ps;
	int i;
};

int main() {
	HasPtr hp1("example");
	HasPtr hp2 = hp1;
	cout << *hp2.ps << " " << hp2.i << endl;
	return 0;
}