//���������� 1.19.������������ ���� ���������, ���������� ���
//���������� ������� 1.4.1 (���. 39), ������� �������� �� �������� �����,
//����������� ����, ���, ����� ������ ������������ ������ ����� �� ���� ���������.

#include <iostream>
#include <utility>

int main() {
	int num1, num2;
	std::cout << "Enter two integers: ";
	std::cin >> num1 >> num2;
	if (num1 > num2) {
		std::swap(num1, num2);
	}
	while (num1 <= num2) {
		std::cout << num1 << std::endl;
		++num1;
	}
	return 0;
}