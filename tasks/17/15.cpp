//���������� 17.15.�������� ���������, ��������� ����� ������ ����,
//���������� ������� "\ ����� �, ����� ��� ����� �"'. ����������� 
//����������� ��� ����� ������������� ����� � ����� ���������� ��� ��������.
//��������� ���� ��������� �� ������� ����, ������� �������� � ��
//�������� ��� �������.

#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main() {
	regex pattern(R"(.*[^c]ei.*)", regex::icase);
	string word;
	cout << "Enter a word to check: ";
	while (cin >> word) {
		if (regex_search(word, pattern)) {
			cout << word << " violates the rule." << endl;
		} else {
			cout << word << " does not violate the rule." << endl;
		}
		cout << "Enter a word to check: ";
	}
	return 0;
}