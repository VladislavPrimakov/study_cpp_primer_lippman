//Упражнение 1.14.Сравните циклы с использованием операторов for и while
//в двух предыдущих упражнениях.Каковы преимущества и недостатки
//каждого из них в разных случаях ?

#include <iostream>

int main() {
	int i = 10;
	while (i >= 0) {
		std::cout << i << std::endl;
		--i;
	}

	for (int i = 10; i >= 0; --i) {
		std::cout << i << std::endl;
	}

	return 0;
}
