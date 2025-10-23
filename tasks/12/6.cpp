//���������� 12.6.�������� �������, ������� ���������� �����������
//��������� ������ ����� �����.��������� ���� ������ ������ �������,
//������� ������ �������� ��� ��������� �� ������������ ���������� �����.
//��������� ������ ������ �������, ��������� ����������� ����� ��������.
//�� �������� ������� ������ � ���������� ������.

#include <iostream>
#include <vector>
using namespace std;

vector<int>* createVector() {
	return new vector<int>;
}

void readValues(vector<int>* vec) {
	int value;
	cout << "Enter integers (CTRL+Z to end):" << endl;
	while (cin >> value) {
		vec->push_back(value);
	}
}

void printValues(const vector<int>* vec) {
	cout << "You entered:" << endl;
	for (const int& val : *vec) {
		cout << val << " ";
	}
	cout << endl;
}

int main() {
	auto v = createVector();
	readValues(v);
	printValues(v);
	delete v;
	printValues(v);
	return 0;
}