//���������� 6.21.�������� �������, ���������� �������� ���� int
//� ��������� �� ��� int, � ������������ �������� ���� int, ���� ���
//������, ��� ��������, �� ������� ��������� ���������, ���� ������ ���.
//����� ��� ������� ������������ ��� ��������� ?

#include <iostream>
using namespace std;

int max_value(const int a, const int* b) {
	if (b == nullptr) {
		throw invalid_argument("Null pointer provided");
	}
	return (a > *b) ? a : *b;
}

int main() {
	int x = 10;
	int y = 20;
	try {
		cout << "Max value: " << max_value(x, &y) << endl;
		cout << "Max value: " << max_value(x, nullptr) << endl;
	} catch (const invalid_argument& e) {
		cerr << "Error: " << e.what() << endl;
	}
	return 0;
}