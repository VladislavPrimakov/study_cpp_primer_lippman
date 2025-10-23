//”пражнение 4.22.ƒополните программу, присваивающую переменной
//значение оценки(высока€, проходна€, не проходна€), еще одной оценки,
//минимально проходной, от 60 до 75 включительно.Ќапишите две версии : одна
//использует только условные операторы; втора€ использует один или несколько
//операторов i f. ак по вашему, какую версию проще пон€ть и почему ?

#include <string>
using namespace std;

int main() {
	int grade = 90;
	string finalgrade = (grade > 90) ? "high pass" : (grade > 75) ? "pass" : (grade > 60) ? "pass" : "fail";
	if (grade > 90) {
		finalgrade = "high pass";
	} else if (grade > 75) {
		finalgrade = "pass";
	} else if (grade >= 60) {
		finalgrade = "low pass";
	} else {
		finalgrade = "fail";
	}
	return 0;
}