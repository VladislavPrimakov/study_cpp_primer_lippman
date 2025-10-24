//Упражнение 14.16.Определите операторы равенства и неравенства для
//классов StrBlob(см.раздел 12.1.1, стр. 582), StrBlobPtr(см.раздел 12.1.6, стр. 604),
//StrVec(см.раздел 13.5, стр. 666) и String(см.раздел 13.5, стр. 671).

#include "StrVec.h"
#include "StrBlob.h"
#include <iostream>

using namespace std;

int main() {
	StrBlob sb1 = {"hello", "world"};
	StrBlob sb2 = {"goodbye", "world"};
	cout << sb1 << " == " << sb2 << " ? " << (sb1 == sb2) << endl;
	cout << sb1 << " != " << sb2 << " ? " << (sb1 != sb2) << endl;
	cout << endl;

	StrBlobPtr sbp1(sb1);
	StrBlobPtr sbp2(sb2);
	cout << sbp1 << " == " << sbp2 << " ? " << (sbp1 == sbp2) << endl;
	cout << sbp1 << " != " << sbp2 << " ? " << (sbp1 != sbp2) << endl;
	cout << endl;

	StrVec sv1 = {"apple", "banana"};
	StrVec sv2 = {"cherry", "date"};
	cout << sv1 << " == " << sv2 << " ? " << (sv1 == sv2) << endl;
	cout << sv1 << " != " << sv2 << " ? " << (sv1 != sv2) << endl;
	return 0;
}