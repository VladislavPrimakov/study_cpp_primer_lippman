//���������� 16.58.�������� ������� emplaceback() ��� ������������
//������ StrVec � ��� ������ Vec, ����������� � ���������� ������� 16.1.2
//(���. 841).

#include "Vec.h"
#include <string>
using namespace std;

int main() {
	Vec<string> v;
	v.emplace_back("Hello");
	v.emplace_back(5, '!');
	v.emplace_back(string("World"));
	v.emplace_back("C++", 2);
	cout << v << endl;
	return 0;
}