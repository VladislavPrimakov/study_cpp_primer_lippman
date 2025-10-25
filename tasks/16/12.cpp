//Упражнение 16.12.Напишите собственные версии шаблонов Blob и BlobPtr,
//включая все константные члены, которые не были представлены в тексте.

#include "Blob.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
	Blob<string> b1 = {"hello", ",", "world"};
	Blob<int> b2 = {1, 2, 3};
	cout << "Blob b1: " << b1 << endl;
	cout << "Blob b2: " << b2 << endl;
	BlobPtr<string> p1(b1);
	BlobPtr<int> p2(b2);
	cout << "BlobPtr p1 points to: " << *p1 << endl;
	cout << "BlobPtr p2 points to: " << *p2 << endl;
	return 0;
}