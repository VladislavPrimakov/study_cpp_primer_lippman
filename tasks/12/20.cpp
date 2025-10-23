//���������� 12.20.�������� ���������, ������� ��������� ������
//�������� ���� � ������������ ������� ������ StrBlob � ����������
//��������� StrBlobPtr ��� ������ ������� ��� ��������.

#include "StrBlob.h"
#include <iostream>
using namespace std;

int main() {
	StrBlob b1;
	{
		StrBlob b2 = {"a", "an", "the"};
		b1 = b2;
		b2.push_back("about");
	};

	for (auto beg = b1.begin(); beg != b1.end(); beg.incr()) {
		cout << beg.deref() << " ";
	}
	return 0;
}