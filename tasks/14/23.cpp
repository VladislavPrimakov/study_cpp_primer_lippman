//���������� 14.23.���������� � ������ ������ StrVec ��������
//���������� ��� ���� initializer_list.

#include "StrVec.h"
#include <iostream>
using namespace std;

int main() {
	StrVec sv;
	sv = {"This", "is", "a", "test"};
	cout << sv << endl;
	return 0;
}