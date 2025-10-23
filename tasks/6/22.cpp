//Упражнение 6.22.Напишите функцию, меняющую местами два указателя
//на тип int.

#include <iostream>
using namespace std;

void swap_pointers(int*& p1, int*& p2) {
	int* temp = p1;
	p1 = p2;
	p2 = temp;
}

int main() {
	int a = 5, * ptr1 = &a;
	int b = 10, * ptr2 = &b;
	cout << "Before swap: *ptr1 = " << *ptr1 << ", *ptr2 = " << *ptr2 << endl;
	swap_pointers(ptr1, ptr2);
	cout << "After swap: *ptr1 = " << *ptr1 << ", *ptr2 = " << *ptr2 << endl;
	return 0;
}