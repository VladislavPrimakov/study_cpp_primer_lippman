//���������� 7.43.�����������, ������� ����� NoDef ault, � �������� ����
//�����������, ���������� �������� ���� int, �� ��� ������������
//������������.���������� ����� �, � �������� ���� ���������� - ���� ����
//No Default.���������� ����������� ����������� ��� ������ �.

#include <vector>
using namespace std;

class NoDefault {
public:
	NoDefault() {}
	//NoDefault(int) {}
};

class C {
	NoDefault n;
public:
	C() {};
};

int main() {
	vector<C> vec(10);
	return 0;
}