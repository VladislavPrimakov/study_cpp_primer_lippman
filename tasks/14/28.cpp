//���������� 14.28.���������� ��� ������ StrBlobPtr ���������
//�������� � ���������, ����� ��� ����������� �������������� �������� �
//�����������(��.������ 3.5.3 ���. 169).

#include "StrBlob.h"
using namespace std;

int main() {
	StrBlob sb {"Hello", "World", "This", "Is", "StrBlobPtr"};
	StrBlobPtr sbp(sb);
	cout << "Current element: " << sbp.deref() << endl;
	sbp = sbp + 2;
	cout << "After adding 2: " << sbp.deref() << endl;
	sbp = sbp - 1;
	cout << "After subtracting 1: " << sbp.deref() << endl;
	sbp += 2;
	cout << "After += 2: " << sbp.deref() << endl;
	sbp -= 3;
	cout << "After -= 3: " << sbp.deref() << endl;
	return 0;
}