//Упражнение 13.40.Добавьте в класс StrVec конструктор, получающий
//аргумент типа initializer_list<string>.

#include <iostream>
#include <string>
#include "StrVec.h"

int main() {
	StrVec sv = {"Hello", "World", "!"};
	std::cout << "Copied Size: " << sv.size() << ", Copied Capacity: " << sv.capacity() << std::endl;
	return 0;
}