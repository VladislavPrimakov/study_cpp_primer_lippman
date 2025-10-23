//���������� 7.23.�������� ����������� ������ ������ Screen.

//���������� 7.24.�������� � ���� ����� Screen ��� ������������ :
//�����������; ���������� ������, ������ � ����������� ����������
//��������������� ����������� ��������; ���������� ������, ������ �
//����������� ������ ��� ����������� ������.

//���������� 7.27.�������� ������� move(), set() � display() � ����
//������ ������ Screen.��������� ���� �����, �������� ��������� ��� :

//���������� 7.32.���������� ����������� ������ ������� Screen � window_
//mgr, � ������� ������� clear() �������� ������ ������ Windowmgr �
//������ ������ Screen.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Screen {
	size_t cursor = 0;
	size_t height = 0;
	size_t width = 0;
	string contents;
public:
	Screen() = default;
	Screen(size_t ht, size_t wd) : height(ht), width(wd), contents(ht* wd, ' ') {}
	Screen(size_t ht, size_t wd, char c) : height(ht), width(wd), contents(ht* wd, c) {}
	Screen& move(size_t h, size_t w);
	Screen& set(char c);
	Screen& display(ostream& os);
	friend class Windowmgr;

};

class Windowmgr {
	void clear(size_t);
private:
	vector<class Screen> screens {Screen(24, 80, ' ')};
};