//���������� 5.14.�������� ��������� ��� ������ ����� �� ������������
//���������� ����� � ������ ����������� ����.��������� ������ ��������
//�� ����� �����, ��� ���� ����� ��������������� �������������� ����� ��.
//��������� ���������� ���������� ���������� � ����������� �����.
//���������� ������������ ���������� ���������� ��� ���������, ��� �������
//���������� �� ����.��������, ��� ����� how now now now brown cow
//cow ����� ������ �������, ��� ����� now ����������� ��� ����.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<string> words;
	vector<int> counts;
	string s;
	cout << "Enter text: ";
	while (cin >> s) {
		words.push_back(s);
		counts.push_back(0);
	}
	for (auto w : words) {
		for (size_t i = 0; i < words.size(); i++) {
			if (w == words[i]) {
				++counts[i];
			}
		}
	}
	size_t max = 0;
	size_t index = 0;
	for (size_t i = 0; i < counts.size(); i++) {
		if (counts[i] > max) {
			max = i;
			index = i;
		}
	}
	cout << "The word '" << words[index] << "' is repeated " << counts[index] << " times." << endl;
}