//���������� 13.8.�������� �������� ���������� ��� ������ HasPtr ��
//���������� 13.5 ������� 13.1.1 (���.634).������� ������������ �����,
//������ �������� ���������� ������ ���������� ������, �� �������
//��������� ��������� ps.

#include <string>
#include <iostream>
using namespace std;

class HasPtr {
public:
	HasPtr(const string& s = string()) : ps(new string(s)), i(0) {}
	HasPtr(const HasPtr& hp) : ps(new string(*hp.ps)), i(hp.i) {}
	HasPtr& operator=(const HasPtr& hp) {
		if (this != &hp) {
			string* new_ps = new string(*hp.ps);
			delete ps;
			ps = new_ps;
			i = hp.i;
		}
		return *this;
	}
	string* ps;
	int i;
};

int main() {
	HasPtr hp1("example");
	HasPtr hp2;
	hp2 = hp1;
	cout << *hp2.ps << " " << hp2.i << endl;
	return 0;
}