//���������� 14.27.�������� � ����� StrBlobPtr ��������� ����������
//� ����������.

#include "StrBlob.h"
using namespace std;

int main() {
	StrBlob sb = {"Hello", "World", "from", "StrBlobPtr"};
	StrBlobPtr sbp(sb);
	cout << sbp << endl;
	sbp++;
	cout << sbp << endl;
	++sbp;
	cout << sbp << endl;
	sbp--;
	cout << sbp << endl;
	--sbp;
	cout << sbp << endl;
	return 0;
}