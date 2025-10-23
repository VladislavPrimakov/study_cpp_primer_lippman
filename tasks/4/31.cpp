//Упражнение 4.31.Программа этого раздела использовала префиксные
//операторы инкремента и декремента.Объясните, почему были
//использованы префиксные, а не постфиксные версии ? Что следует изменить для
//использования постфиксных версий ? Перепишите программу с
//использованием постфиксных операторов.

#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> ivec(10);
	size_t cnt = ivec.size();
	for (size_t ix = 0; ix != ivec.size(); ++ix, --cnt) {
		ivec[ix] = static_cast<int>(cnt);
	}
	for (auto i : ivec) {
		cout << i << " ";
	}
	return 0;
}