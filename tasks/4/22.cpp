//���������� 4.22.��������� ���������, ������������� ����������
//�������� ������(�������, ���������, �� ���������), ��� ����� ������,
//���������� ���������, �� 60 �� 75 ������������.�������� ��� ������ : ����
//���������� ������ �������� ���������; ������ ���������� ���� ��� ���������
//���������� i f.��� �� ������, ����� ������ ����� ������ � ������ ?

#include <string>
using namespace std;

int main() {
	int grade = 90;
	string finalgrade = (grade > 90) ? "high pass" : (grade > 75) ? "pass" : (grade > 60) ? "pass" : "fail";
	if (grade > 90) {
		finalgrade = "high pass";
	} else if (grade > 75) {
		finalgrade = "pass";
	} else if (grade >= 60) {
		finalgrade = "low pass";
	} else {
		finalgrade = "fail";
	}
	return 0;
}