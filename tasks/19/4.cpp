//Упражнение 19.4.Используя классы, определенные в первом упражнении,
//перепишите следующий код так, чтобы преобразовать выражение* ра в тип С& :

#include <iostream>
using namespace std;

class A {
public:
	virtual ~A() = default;
};
class В : public A {};
class С : public В {};
class D : public В, public A {};



int main() {
	A* ра = new С;
	try {
		С& рс = dynamic_cast<С&>(*ра);
		cout << "Conversion successful" << endl;
	} catch (bad_cast& e) {
		cout << "Conversion failed: " << e.what() << endl;
	}
	return 0;
}