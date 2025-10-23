//Упражнение 4.37.Перепишите каждое из следующих приведений старого
//стиля так, чтобы использовался именованный оператор приведения.
//int i; double d; const string* ps; char* pc; void* pv;
//(a) pv = (void*) ps; (b) i = int(*pc);
//(c) pv = &d; (d) pc = (char*) pv;

#include <string>
using namespace std;

int main() {
	int i;
	double d;
	const string str;
	const string* ps = &str;
	char ch;
	char* pc = &ch;
	void* pv;
	// (a) pv = (void*) ps;
	pv = static_cast<void*>(const_cast<string*>(ps));
	// (b) i = int(*pc);
	i = static_cast<int>(*pc);
	// (c) pv = &d;
	pv = static_cast<void*>(&d);
	// (d) pc = (char*) pv;
	pc = static_cast<char*>(pv);
	return 0;
}