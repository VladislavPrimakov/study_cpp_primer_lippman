//���������� 1.5.� ����� ��������� ���� ����� ����������� ����
//������� ��������.���������� ��������� ���, ����� ��� ������ �� �����
//������� �������� ������������� ��������� ��������.

#include <iostream>

int main()
{
	std::cout << "Enter two numbers:" << std::endl;
	int vl = 0, v2 = 0;
	std::cin >> vl >> v2;
	std::cout << "The multiplication of ";
	std::cout << vl;
	std::cout << " and ";
	std::cout << v2;
	std::cout << " is ";
	std::cout << vl * v2;
	std::cout << std::endl;
	return 0;
}