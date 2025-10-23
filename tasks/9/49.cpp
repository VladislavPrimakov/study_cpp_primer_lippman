//���������� 9.49.� �������� ����� ���� ����������� �����,
//������������� ���� �������� ������, ��� � d ��� f, ��� �����������, ���� ��������
//������, ��� p ��� g.�������� ���������, ������� ������ ����������
//����� ���� � �������� ����� ������� �����, �� ���������� ��
//�����������, �� ����������� ���������.

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	stringstream ss("A deep, fragrant garden offered happy frogs shelter, while the small cat sat near a warm stone in the sun");
	string word, longest_word;
	while (ss >> word) {
		auto i = word.find_first_of("dfpg");
		if (word.size() > longest_word.size() && word.find_first_of("dfpg") == string::npos) {
			longest_word = word;
		}
	}
	cout << "Base sting: " << ss.str() << endl;
	cout << "The longest word without ascenders or descenders is: " << longest_word << endl;
	return 0;
}