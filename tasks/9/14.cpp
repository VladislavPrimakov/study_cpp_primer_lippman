//���������� 9.14.�������� ���������, ������������� ��������
//��������� ������ ���������� �� ���������� ������ � ����� �(��� char*)
//��������� ������� �����.

#include <iostream>
#include <vector>
#include <array>
#include <string>
using namespace std;

int main() {
	array<const char*, 5> cstr_list {"Hello", "world", "this", "is", "C++"};
	vector<string> str_vector(cstr_list.begin(), cstr_list.end());
	cout << "Vector of strings:" << endl;
	for (const auto& str : str_vector) {
		cout << str << " ";
	}
	cout << endl;
	return 0;
}