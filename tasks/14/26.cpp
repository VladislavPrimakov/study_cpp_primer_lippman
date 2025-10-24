//���������� 14.26.���������� ��������� �������������� ��� �������
//StrVec, String, StrBlob � StrBlobPtr.

#include "StrVec.h"
#include "StrBlob.h"
#include <iostream>
using namespace std;

int main() {
	StrBlob sb = {"Hello", "World", "from", "StrBlob"};
	for (size_t i = 0; i < sb.size(); ++i) {
		cout << sb[i] << " ";
	}
	cout << endl;

	StrBlobPtr sbp(sb);
	cout << sbp[5] << endl;

	StrVec sv = {"Hello", "World", "from", "StrVec"};
	for (size_t i = 0; i < sv.size(); ++i) {
		cout << sv[i] << " ";
	}
	cout << endl;
	return 0;
}