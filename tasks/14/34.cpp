//���������� 14.34.���������� ����� ������� ������� ��� ����������
//�������� ��������� ��������� : �������� ������ ����� ������ ������
//�������� ��� ���������.�� ������ ��������� ���� ������ �������� �, ����
//��� �������� �������, ���������� ���� ������ ��������; � ���������
//������ �� ������ ���������� ���� ������ ��������.

#include <iostream>
using namespace std;

class Conditional {
public:
	int operator()(bool c, int a, int b) {
		if (c) {
			return a;
		} else {
			return b;
		}
	}
};

int main() {
	Conditional cond;
	cout << "Condition true: " << cond(true, 10, 20) << endl;
	cout << "Condition false: " << cond(false, 10, 20) << endl;
	return 0;
}