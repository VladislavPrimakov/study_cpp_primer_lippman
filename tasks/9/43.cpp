//���������� 9.43.�������� �������, ���������� ��� ������ : s, oldVal
//� newVal.��������� ���������, � ����� ������� insert(), � erase()
//�������� ��� �������������� � ������ s ���������� ������ oldVal �������
//newVal.��������� ������� �� ������� ������ ����� ������������
//����������, ��� "tho" �� "though" � "thru" �� "through".


#include <iostream>
#include <string>
using namespace std;

string& f(string& s, const string& oldVal, const string& newVal) {
	string::size_type index = 0;
	while ((index = s.find(oldVal, index)) != -1) {
		s.erase(index, oldVal.size());
		s.insert(index, newVal);
		index += newVal.size();
	}
	return s;
}

int main() {
	string s = "tho I went thru the tho";
	cout << f(s, "tho", "though") << endl;
	return 0;
}