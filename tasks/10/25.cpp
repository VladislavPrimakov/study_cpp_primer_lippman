//���������� 10.25.� ����������� ������� 10.3.2 (���. 501) ���� ��������
//������ ������� biggies(), ������������ �������� partition().
//���������� ��� ������� ���, ����� ������������ ������� checksize �
//� bind() .

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;

void elimDups(vector<string>& words) {
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

bool check_size(const string& s, size_t sz) {
	return s.size() > sz;
}


void biggies(vector<string>& words, size_t sz) {
	elimDups(words);
	stable_sort(words.begin(), words.end(), [](const string& a, const string& b) { return a.size() < b.size(); });
	auto it = partition(words.begin(), words.end(), bind(check_size, _1, ref(sz)));
	auto count = it - words.begin();
	cout << "Num of unique words which size is more than " << sz << ": " << count << endl;
}


int main() {
	vector<string> words = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
	biggies(words, static_cast<size_t>(4));
	return 0;
}