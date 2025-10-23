//���������� 9.31.��������� �� ���.455, ��������� ������ �
//����������� �������� ��������, �� ����� �������� � ����������� list ���
//forwardlist.������ ? ����������� ��������� ���, ����� ��� ��������
//� � ����� ������ ����.

#include <iostream>
#include <forward_list>
using namespace std;

int main() {
	forward_list<int> fl = {0,1,2,3,4,5,6,7,8,9};
	auto iter_curr = fl.begin();
	auto iter_prev = fl.before_begin();
	while (iter_curr != fl.end()) {
		if (*iter_curr % 2) {
			iter_curr = fl.insert_after(iter_curr, *iter_curr);
			iter_prev = iter_curr;
			++iter_curr;
		} else {
			iter_curr = fl.erase_after(iter_prev);
		}
	}
	for (const auto& i : fl) {
		cout << i << " ";
	}
	return 0;
}