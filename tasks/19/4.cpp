//���������� 19.4.��������� ������, ������������ � ������ ����������,
//���������� ��������� ��� ���, ����� ������������� ���������* �� � ��� �& :

#include <iostream>
using namespace std;

class A {
public:
	virtual ~A() = default;
};
class � : public A {};
class � : public � {};
class D : public �, public A {};



int main() {
	A* �� = new �;
	try {
		�& �� = dynamic_cast<�&>(*��);
		cout << "Conversion successful" << endl;
	} catch (bad_cast& e) {
		cout << "Conversion failed: " << e.what() << endl;
	}
	return 0;
}