//Упражнение 3.36.Напишите программу, сравнивающую два массива на
//равенство.Напишите подобную программу для сравнения двух векторов.


#include <iostream>
using namespace std;

int main() {
	int arr1[] = {1, 2, 3, 4, 5};
	int arr2[] = {1, 2, 3, 4, 5};
	const size_t size = sizeof(arr1) / sizeof(arr1[0]);
	if (size != sizeof(arr2) / sizeof(arr2[0])) {
		cout << "Arrays are not equal in size." << endl;
	} else {
		bool areEqual = true;
		for (size_t i = 0; i < size; ++i) {
			if (*(arr1 + i) != *(arr2 + i)) {
				areEqual = false;
				break;
			}
		}
		if (areEqual) {
			cout << "Arrays are equal." << endl;
		} else {
			cout << "Arrays are not equal." << endl;
		}
	}
	return 0;
}