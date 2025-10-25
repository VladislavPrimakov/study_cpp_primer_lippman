//���������� 16.4.�������� ������, ����������� ��� ������������
//�������� f ind().������� ����� ��������� � ���� ���������� ���� ������� :
//���� � ��� ������������� ���������� - ���������� ������� � ������ �
//��� ���� ��������.����������� ���� ������� ��� ������ ���������
//�������� � ������� vector<int> � ������ list<string>.

#include <iostream>
#include <vector>
#include <list>
using namespace std;

namespace my {
	template <typename Iter, typename T>
	Iter find(Iter begin, Iter end, const T& value) {
		for (Iter it = begin; it != end; ++it) {
			if (*it == value) {
				return it;
			}
		}
		return end;
	}
}

int main() {
	vector<int> vec = {1, 2, 3, 4, 5};
	list<string> lst = {"apple", "banana", "cherry"};
	int intValue = 3;
	string strValue = "banana";
	auto vecIt = my::find(vec.begin(), vec.end(), intValue);
	if (vecIt != vec.end()) {
		cout << "Found " << intValue << " in vector at position " << distance(vec.begin(), vecIt) << endl;
	} else {
		cout << intValue << " not found in vector" << endl;
	}
	auto lstIt = my::find(lst.begin(), lst.end(), strValue);
	if (lstIt != lst.end()) {
		cout << "Found " << strValue << " in list" << endl;
	} else {
		cout << strValue << " not found in list" << endl;
	}
	return 0;
}