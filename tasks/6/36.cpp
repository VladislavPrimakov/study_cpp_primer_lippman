//���������� 6.36.�������� ���������� �������, ������������ ������
//�� ������ �� ������ �����, �� ��������� �� ���������� ���
//������������� ��������, �� ������������ decltype ��� ��������� ����.

#include <iostream>
#include <string>
using namespace std;

const string(&func(const string(&arr)[10]))[10]{
	return  arr;
}


int main() {
	string arr[10] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
	const string(&ref)[10] = func(arr);
	for (auto s : ref) {
		cout << s << " ";
	}
	return 0;
}