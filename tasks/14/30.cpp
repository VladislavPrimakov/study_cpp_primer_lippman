//���������� 14.30.�������� ��������� ��������� � �������� � �������
//� ����� StrBlobPtr

#include "StrBlob.h"
using namespace std;

int main() {
	StrBlob sb {"Hello", "World", "This", "Is", "StrBlobPtr"};
	StrBlobPtr sbp(sb);
	cout << "Current element using deref(): " << sbp.deref() << endl;
	cout << "Current element using operator*(): " << *sbp << endl;
	cout << "Accessing member function of string using operator->(): " << sbp->size() << endl;
	return 0;
}