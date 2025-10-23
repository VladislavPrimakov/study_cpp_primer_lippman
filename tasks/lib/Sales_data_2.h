//Упражнение 7.12.Переместите определение конструктора Salesdata(),
//получающего объект istream, в тело класса Sales_data.

//Упражнение 7.14.Напишите версию стандартного конструктора, явно
//инициализирующую переменные - члены значениями, предоставленными
//внутриклассовыми инициализаторами.

//Упражнение 7.26.Определите функцию Salesdata : : avg_price как
//встраиваемую.

//Упражнение 7.38.Конструктору, получающему аргумент типа istream&,
//можно предоставить объект cin как аргумент по умолчанию.Напишите
//объявление конструктора, использующего объект cin как аргумент по
//умолчанию.

//Упражнение 7.41.Перепишите собственную версию класса Sales_data,
//чтобы использовать делегирующие конструкторы.Добавьте в тело каждого
//конструктора оператор, выводящий сообщение всякий раз, когда он
//выполняется.Напишите объявления для создания объекта класса Sales_data
//любыми возможными способами.Изучите вывод и удостоверьтесь, что
//понимаете порядок выполнения делегирующих конструкторов.

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

class Sales_data {
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::ostream& print(std::ostream&, const Sales_data&);
	friend std::istream& read(std::istream&, Sales_data&);
public:
	Sales_data(const std::string& s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p* n) {}
	Sales_data() : Sales_data({}, {}, {}) {}
	Sales_data(const std::string& s) : Sales_data(s, {}, {}) {}
	Sales_data(std::istream& is) : Sales_data() {
		read(is, *this);
	}
	std::string isbn() const {
		return bookNo;
	}
	Sales_data& combine(const Sales_data&);
	inline double avg_price() const;
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream& print(std::ostream&, const Sales_data&);
std::istream& read(std::istream&, Sales_data&);

inline bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs) {
	return lhs.isbn() < rhs.isbn();
}
#endif
