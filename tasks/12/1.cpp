//���������� 12.1.������� ��������� ����� ����� ������� �1 � �2 � �����
//����� ���� ?

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
	cout << "Size of bl: " << b1.size() << endl;
	return 0;
}