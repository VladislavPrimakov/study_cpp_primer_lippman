//���������� 9.38.�������� ���������, ����������� ����������� ����
//������� � ����������, ������� �� �����������.

#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> vi;
	size_t size = 0;
	cout << "Initial size: " << vi.size() << ", capacity: " << vi.capacity() << endl;
	for (int i = 0; i < 100; ++i) {
		vi.push_back(i);
		if (vi.size() != size) {
			size = vi.size();
			cout << "Size: " << vi.size() << ", capacity: " << vi.capacity() << endl;
		}
	}
	return 0;
}