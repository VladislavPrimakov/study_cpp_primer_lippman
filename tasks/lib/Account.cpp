//Упражнение 7.57.Напишите собственную версию класса Account.

#include <string>
#include <vector>

class Account {
public:
public:
	void calculate() {
		amount += amount * interestRate;
	}
	static double rate() {
		return interestRate;
	}
	static void rate(double r) {
		interestRate = r;
	}
private:
	static double interestRate;
	static constexpr int period = 30;
	double daily_tbl[period];
	std::string owner;
	double amount;
	static double initRate() {
		interestRate = 0.025;
	}
};