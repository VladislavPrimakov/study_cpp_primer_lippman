//���������� 14.16.���������� ��������� ��������� � ����������� ���
//������� StrBlob(��.������ 12.1.1, ���. 582), StrBlobPtr(��.������ 12.1.6, ���. 604),
//StrVec(��.������ 13.5, ���. 666) � String(��.������ 13.5, ���. 671).

#include "StrVec.h"
#include "StrBlob.h"
#include <iostream>

using namespace std;

int main() {
	StrBlob sb1 = {"hello", "world"};
	StrBlob sb2 = {"goodbye", "world"};
	cout << sb1 << " == " << sb2 << " ? " << (sb1 == sb2) << endl;
	cout << sb1 << " != " << sb2 << " ? " << (sb1 != sb2) << endl;
	cout << endl;

	StrBlobPtr sbp1(sb1);
	StrBlobPtr sbp2(sb2);
	cout << sbp1 << " == " << sbp2 << " ? " << (sbp1 == sbp2) << endl;
	cout << sbp1 << " != " << sbp2 << " ? " << (sbp1 != sbp2) << endl;
	cout << endl;

	StrVec sv1 = {"apple", "banana"};
	StrVec sv2 = {"cherry", "date"};
	cout << sv1 << " == " << sv2 << " ? " << (sv1 == sv2) << endl;
	cout << sv1 << " != " << sv2 << " ? " << (sv1 != sv2) << endl;
	return 0;
}