//Упражнение 14.34.Определите класс объекта функции для выполнения
//действий условного оператора : оператор вызова этого класса должен
//получать три параметра.Он должен проверить свой первый параметр и, если
//эта проверка успешна, возвратить свой второй параметр; в противном
//случае он должен возвратить свой третий параметр.

#include <iostream>
using namespace std;

class Conditional {
public:
	int operator()(bool c, int a, int b) {
		if (c) {
			return a;
		} else {
			return b;
		}
	}
};

int main() {
	Conditional cond;
	cout << "Condition true: " << cond(true, 10, 20) << endl;
	cout << "Condition false: " << cond(false, 10, 20) << endl;
	return 0;
}