//Упражнение 10.3.Примените функцию accumulate() для суммирования
//элементов вектора vector<int>.

#include <iostream>
#include <vector>
#include <numeric> 
using namespace std;

int main() {
	vector <int> v = {1,2,3,4,5,6,3,3,2};
	cout << "Sum is " << accumulate(v.begin(), v.end(), 0) << endl;
	return 0;
}