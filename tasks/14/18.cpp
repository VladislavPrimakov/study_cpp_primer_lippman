//Упражнение 14.18.Определите операторы отношения для классов StrBlob,
//StrBlobPtr, StrVec И String.

#include "StrVec.h"
#include "StrBlob.h"
#include <iostream>

using namespace std;

int main() {
	StrBlob sb1 = {"hello", "world"};
	StrBlob sb2 = {"hello", "world"};
	StrBlob sb3 = {"goodbye", "world"};
	cout << sb1 << " > " << sb3 << " ? " << (sb1 > sb3) << endl;
	cout << sb1 << " >= " << sb2 << " ? " << (sb1 >= sb2) << endl;
	cout << sb1 << " < " << sb3 << " ? " << (sb1 < sb3) << endl;
	cout << sb1 << " <= " << sb3 << " ? " << (sb1 <= sb3) << endl;
	cout << endl;

	StrBlobPtr sbp1(sb1);
	StrBlobPtr sbp2(sb2, 1);
	StrBlobPtr sbp3(sb3);
	cout << sbp1 << " > " << sbp3 << " ? " << (sbp1 > sbp3) << endl;
	cout << sbp1 << " >= " << sbp2 << " ? " << (sbp1 >= sbp2) << endl;
	cout << sbp1 << " < " << sbp3 << " ? " << (sbp1 < sbp3) << endl;
	cout << sbp1 << " <= " << sbp1 << " ? " << (sbp1 <= sbp1) << endl;
	cout << endl;

	StrVec sv1 = {"apple", "banana"};
	StrVec sv2 = {"apple", "banana"};
	StrVec sv3 = {"cherry", "date"};
	cout << sv1 << " > " << sv3 << " ? " << (sv1 > sv3) << endl;
	cout << sv1 << " >= " << sv2 << " ? " << (sv1 >= sv2) << endl;
	cout << sv1 << " < " << sv3 << " ? " << (sv1 < sv3) << endl;
	cout << sv1 << " <= " << sv3 << " ? " << (sv1 <= sv3) << endl;
	return 0;
}