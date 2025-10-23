//Упражнение 7.4.Напишите класс по имени Person, представляющий имя
//и адрес человека.Используйте для содержания каждого из этих членов тип
//string.В последующих упражнениях в этот класс будут добавлены новые
//средства.

//Упражнение 7.5.Снабдите класс Person операциями возвращения имени
//и адреса.Должны ли эти функции быть константами ? Объясните свой выбор.

//Упражнение 7.9.Добавьте в код, написанный для упражнений в
//разделе 7.1.2 (стр. 339), операции чтения и вывода объектов класса Person.

//Упражнение 7.15.Добавьте соответствующие конструкторы в класс Person.

//Упражнение 7.22.Измените свой класс Person так, чтобы скрыть его
//реализацию.

#include <iostream>
#include <string>
using namespace std;
class Person {
	string name;
	string address;
public:
	string get_name() const {
		return name;
	}
	string get_address() const {
		return address;
	}
	Person() = default;
	Person(const string& n, const string& a) : name(n), address(a) {}
	friend istream& read(istream&, Person&);
	friend ostream& print(ostream&, const Person&);
};

istream& read(istream& is, Person& p) {
	is >> p.name >> p.address;
	return is;
}

ostream& print(ostream& os, const Person& p) {
	os << p.get_name() << " " << p.get_address();
	return os;
}