//Упражнение 13.18.Определите класс Employee, содержащий имя
//сотрудника и его уникальный идентификатор.Снабдите класс стандартным
//конструктором и конструктором, получающим строку, представляющую имя
//сотрудника.Каждый конструктор должен создавать уникальный
//идентификатор за счет приращения статической переменной - члена.

#include <string>
#include <iostream>
using namespace std;

class Employee {
public:
	Employee() : name(""), id(++id_counter) {}
	Employee(const string& emp_name) : name(emp_name), id(++id_counter) {}
	string getName() const {
		return name;
	}
	int getId() const {
		return id;
	}
private:
	string name;
	int id;
	static int id_counter;
};

int Employee::id_counter = 0;

int main() {
	Employee emp1("Alice");
	Employee emp2("Bob");
	Employee emp3;
	cout << "Employee 1: " << emp1.getName() << ", ID: " << emp1.getId() << endl;
	cout << "Employee 2: " << emp2.getName() << ", ID: " << emp2.getId() << endl;
	cout << "Employee 3: " << emp3.getName() << ", ID: " << emp3.getId() << endl;
	return 0;
}