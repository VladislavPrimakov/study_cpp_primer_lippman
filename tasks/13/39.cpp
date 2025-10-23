//Упражнение 13.39.Напишите собственную версию класса StrVec, включая
//функции reserve(), capacity() (см.раздел 9.4, стр.458) и resize()
//(см.раздел 9.3.5, стр. 452).

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