//���������� 18.9.���������� ��������� � ���� ������� ������
//���������� ���������� �������� �������� � ���������� ��������� ��������
//���������� ������ Salesdata ���, ����� �� ��������� ����������.

#include "Sales_data.h"
using namespace std;

int main() {
	Sales_data item1("12345", 10, 20.0);
	Sales_data item2("54321", 5, 15.0);
	try {
		item1 += item2;
	} catch (const isbn_mismatch& e) {
		cerr << e.what() << endl;
	}
	return 0;
}