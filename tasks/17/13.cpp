//���������� 17.11.���������� ��������� ������, ������� ��������
//������������� ������, ����������� ���������(���� / �� ����) ������ ��
//����������� �� 10 ��������.����� ���������(���� ��� ������ �����������)
//���������� ������ � ��������� ������, ���� � ����������� ������ 100
//�������� ?
//���������� 17.12.��������� ��������� ������ �� ����������� �������,
//�������� �������, ���������� ����� ������� � ��������, ����������
//���������� / ������������ �����, � ���������� ���������� �����������
//��������������.
//���������� 17.13.�������� ������������� ������, ����������
//���������� ������(�� / ���) �� ������� �����������.����������� ��� ��� ��������
//������ ����������� �������� ��� ��������� ������ �� ���������� ����
//����������.

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
