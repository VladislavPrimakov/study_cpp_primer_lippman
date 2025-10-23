//”пражнение 5.3.»спользу€ оператор зап€той(см.раздел 4.10, стр. 217),
//перепишите цикл while из раздела 1.4.1 (стр. 38) так, чтобы блок стал больше
//не нужен.ќбъ€сните, улучшило ли это удобочитаемость кода.

#include <iostream>
using namespace std;

int main() {
	int sum = 0;
	int val = 1;
	while (val <= 10)
		sum += val, ++val;
	cout << "Sum of 1 to 10 inclusive is " << sum << endl;
}