//���������� 14.38.�������� �����, ����������� ������������ �����
//�������� ������ ���������� ��������.����������� ����� ������ �
//��������� ��� ���������� � ���������� ���� �� ������� �����, �������
//������� �� 1 �� 10 ������������.


#include <iostream>
#include <string>
using namespace std;

class LengthChecker {
public:
	LengthChecker(size_t _minLength, size_t _maxLength) : minLength(_minLength), maxLength(_maxLength) {}
	bool operator()(const string& str) const {
		return str.size() >= minLength && str.size() <= maxLength;
	}
private:
	size_t minLength;
	size_t maxLength;
};

int main() {
	LengthChecker checker(1, 10);
	string testStr1 = "Hello";
	string testStr2 = "World!";
	cout << "Test string 1: " << testStr1 << " - Match: " << (checker(testStr1) ? "Yes" : "No") << endl;
	cout << "Test string 2: " << testStr2 << " - Match: " << (checker(testStr2) ? "Yes" : "No") << endl;
	return 0;
}