//���������� 6.46.�������� �� ���������� ������� isShorter ���
//constexpr ? ���� ��, �� �������� ���.� ��������� ������ ���������,
//������ ���.

#include <iostream>
#include <string>
#include <string_view>
using namespace std;

constexpr bool isShorter(const string& s1, const string& s2) {
	return s1.size() < s2.size();
}

//constexpr bool isShorter(string_view s1, string_view s2) {
//	return s1.size() < s2.size();
//}


int main() {
	auto result = isShorter("hello", "world!");
	cout << boolalpha << result << endl;
	return 0;
}