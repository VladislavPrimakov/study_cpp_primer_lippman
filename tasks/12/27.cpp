//���������� 12.27.������ TextQuery � QueryResult ���������� ������
//�� �����������, ������� ��� ���� ������� �����.�� ���������� ������,
//�������� ����������� ������ ���� �������.

#include <fstream>
#include "TextQuery.h"

int main(int agrc, char* argv[]) {
	if (agrc != 2) {
		std::cerr << "Usage: " << argv[0] << " <file>\n";
		return 1;
	}
	std::ifstream infile(argv[1]);
	if (!infile) {
		std::cerr << "Could not open file " << argv[1] << "\n";
		return 1;
	}
	runQueries(infile);
	return 0;
}