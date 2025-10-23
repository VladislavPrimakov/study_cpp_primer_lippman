//���������� 8.9.����������� �������, ���������� ��� �������
//���������� 8.1.2 (���. 404), ��� ������ ����������� ������� ������ istringstream.

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

istream& func(istream& is) {
	string line;
	while (getline(is, line)) {
		cout << line << endl;
	}
	is.clear();
	return is;
}


int main() {
	istringstream iss("123");
	func(iss);
	return 0;
}
