//”пражнение 17.11.ќпределите структуру данных, котора€ содержит
//целочисленный объект, позвол€ющий отследить(сдал / не сдал) ответы на
//контрольную из 10 вопросов. акие изменени€(если они вообще понадоб€тс€)
//необходимо внести в структуру данных, если в контрольной станет 100
//вопросов ?
//”пражнение 17.12.»спользу€ структуру данных из предыдущего вопроса,
//напишите функцию, получающую номер вопроса и значение, означающее
//правильный / неправильный ответ, и измен€ющую результаты контрольной
//соответственно.
//”пражнение 17.13.—оздайте целочисленный объект, содержащий
//правильные ответы(да / нет) на вопросы контрольной.»спользуйте его дл€ создани€
//оценок контрольных вопросов дл€ структуры данных из предыдущих двух
//упражнений.

#include <bitset>
#include <iostream>
using namespace std;

template <size_t N>
struct QuizResults {
	bitset<N> results;
	void recordAnswer(size_t questionNumber, bool isCorrect) {
		if (questionNumber < N) {
			results.set(questionNumber, isCorrect);
		} else {
			cerr << "Question number out of range." << endl;
		}
	}
	void printResults() const {
		cout << "Quiz Results: " << results << endl;
	}
};

int main() {
	QuizResults<10> quiz;
	quiz.recordAnswer(0, true);
	quiz.recordAnswer(1, false);
	quiz.recordAnswer(2, true);
	quiz.recordAnswer(3, true);
	quiz.recordAnswer(4, false);
	quiz.recordAnswer(5, true);
	quiz.recordAnswer(6, true);
	quiz.recordAnswer(7, false);
	quiz.recordAnswer(8, true);
	quiz.recordAnswer(9, true);

	quiz.printResults();
	return 0;
}
