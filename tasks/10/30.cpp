//Упражнение 10.30.Используйте потоковые итераторы, а также функции
//sort() и сору() для чтения последовательности целых чисел со
//стандартного устройства ввода, их сортировки и последующего вывода на
//стандартное устройство вывода.

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	istream_iterator<int> ii(cin), eof;
	vector<int> vec(ii, eof);
	sort(vec.begin(), vec.end());
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
	return 0;
}