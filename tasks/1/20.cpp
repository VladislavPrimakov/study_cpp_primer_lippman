//���������� 1.20.�� ������ http://www.informit.com/title/032174113
//� �������� ���� ������ ����� ���������� ����� ����� Salesi tern.h.
//���������� ���� ���� � ���� ������� ������� � ����������� ��� ���������
//���������, ������� ������ ����� ���������� ��������� ���� � ���������� ��
//�� ����������� ���������� ������.

#include "Sales_item.h"
#include <iostream>

int main() {
	Sales_item item;
	// read the data for the item
	while (std::cin >> item) {
		// write the item to the standard output
		std::cout << item << std::endl;
	}
	return 0;
}