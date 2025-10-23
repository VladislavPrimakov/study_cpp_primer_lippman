//Упражнение 7.43.Предположим, имеется класс NoDef ault, у которого есть
//конструктор, получающий параметр типа int, но нет стандартного
//конструктора.Определите класс С, у которого есть переменная - член типа
//No Default.Определите стандартный конструктор для класса С.

#include <vector>
using namespace std;

class NoDefault {
public:
	NoDefault() {}
	//NoDefault(int) {}
};

class C {
	NoDefault n;
public:
	C() {};
};

int main() {
	vector<C> vec(10);
	return 0;
}