//���������� 19.6.�������� ��������� ��� ������������� ����������
//��������� �� ��� Querybase � ��������� �� ��� AndQuery(��.������ 15.9.1,
//���. 802).��������� ����������, ��������� ������ ������ AndQuery � ������
//������� �������.�������� ���������, �������������� �����������������
//����������, � ���������, ��� ����� ������������� ���������.

#include "TextQuery.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	Query_base* qb = new AndQuery(Query("word1"), Query("word2"));
	AndQuery* aq = dynamic_cast<AndQuery*>(qb);
	if (aq) {
		cout << "Dynamic cast to AndQuery* successful." << endl;
	} else {
		cout << "Dynamic cast to AndQuery* failed." << endl;
	}
	return 0;
}