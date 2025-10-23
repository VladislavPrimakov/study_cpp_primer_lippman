//”пражнение 7.35.ќбъ€сните код, приведенный ниже.”кажите, какое из
//определений, “уре или initVal, будет использовано дл€ каждого из имен.
//≈сли здесь есть ошибки, найдите и исправьте их.
//typedef string Type;
//Type initVal();
//class Exercise {
//public:
//	typedef double Type;
//	Type setVal(Type);
//	Type initVal();
//private:
//	int val;
//};
//Type Exercise::setVal(Type parm) {
//	val = parm + initVal();
//	return val;
//}

#include <string>
using namespace std;

typedef string Type;
Type initVal();

class Exercise {
public:
	typedef double Type;
	Type setVal(Type);
	Type initVal();
private:
	double val;
};

Exercise::Type Exercise::initVal() {
	return 0.0;
}

Exercise::Type Exercise::setVal(Exercise::Type parm) {
	val = parm + initVal();
	return val;
}


int main() {
	return 0;
}
