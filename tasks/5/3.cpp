//���������� 5.3.��������� �������� �������(��.������ 4.10, ���. 217),
//���������� ���� while �� ������� 1.4.1 (���. 38) ���, ����� ���� ���� ������
//�� �����.���������, �������� �� ��� ��������������� ����.

#include <iostream>
using namespace std;

int main() {
	int sum = 0;
	int val = 1;
	while (val <= 10)
		sum += val, ++val;
	cout << "Sum of 1 to 10 inclusive is " << sum << endl;
}