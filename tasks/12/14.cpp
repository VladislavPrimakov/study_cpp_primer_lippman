//���������� 12.14.�������� ����������� ������ �������,
//������������ ��������� sharedptr ��� ���������� �����������.

#include <iostream>
#include <memory>
#include <string>
#include <functional>
using namespace std;

struct destination {};

struct connection {
	connection() = default;
	connection(destination& d) {};
};

void disconnect(connection* c) {
	cout << "Disconnect" << endl;
}

void f(destination& d) {
	shared_ptr<connection> c(new connection(d), disconnect);
}

int main() {
	destination d;
	f(d);
	return 0;
}