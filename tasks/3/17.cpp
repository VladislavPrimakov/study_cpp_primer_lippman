//���������� 3.17.���������� ������������������ ���� �� ������ � in �
//��������� �� � �������.�������� ��� �����, ����������� ������ � ����������
//������� ������� ����� � ������� �������.���������� ���������������
//�������� �� ������ ���� �� ������.

#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<string> words;
	string word;
	cout << "Enter a sequence of words (CTRL+Z for stop):\n";
	while (cin >> word) {
		words.push_back(word);
	}
	for (auto& w : words) {
		for (auto& ch : w) {
			ch = toupper(ch);
		}
	}
	for (size_t i = 0; i < words.size(); ++i) {
		cout << words[i] << " ";
		if ((i + 1) % 8 == 0) {
			cout << endl;
		}
	}
	return 0;
}