//���������� 13.39.�������� ����������� ������ ������ StrVec, �������
//������� reserve(), capacity() (��.������ 9.4, ���.458) � resize()
//(��.������ 9.3.5, ���. 452).

#include <iostream>
#include <string>
#include "StrVec.h"

int main() {
	StrVec sv;
	sv.push_back("Hello");
	sv.push_back("World");
	std::cout << "Size: " << sv.size() << ", Capacity: " << sv.capacity() << std::endl;
	StrVec sv2 = sv;
	sv2.push_back("!");
	std::cout << "Copied Size: " << sv2.size() << ", Copied Capacity: " << sv2.capacity() << std::endl;
	return 0;
}