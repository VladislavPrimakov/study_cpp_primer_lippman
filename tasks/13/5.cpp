//”пражнение 13.5.Ќапишите с учетом следующего эскиза класса
//конструктор копий, копирующий все переменные - члены. онструктор должен
//динамически резервировать новую строку(см.раздел 12.1.2 стр. 584) и
//копировать объект, на который указывает ps, а не сам указатель ps.

#include <string>
#include <iostream>
using namespace std;

class HasPtr {
public:
	HasPtr(const string& s = string()) : ps(new string(s)), i(0) {}
	HasPtr(const HasPtr& hp) : ps(new string(*hp.ps)), i(hp.i) {}
	string* ps;
	int i;
};

int main() {
	HasPtr hp1("example");
	HasPtr hp2 = hp1;
	cout << *hp2.ps << " " << hp2.i << endl;
	return 0;
}