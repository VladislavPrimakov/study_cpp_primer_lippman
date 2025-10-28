
//Упражнение 17.4.Напишите и проверьте собственную версию функции
//f indBook().

#include "Sales_data.h"
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <numeric>
using namespace std;

using matches = tuple<vector<Sales_data>::size_type, vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator>;

vector<matches> findBook(const vector<vector<Sales_data>>& files, const string& book) {
	vector<matches> ret;
	for (auto it = files.cbegin(); it != files.cend(); ++it) {
		auto found = equal_range(it->cbegin(), it->cend(), book);
		if (found.first != found.second)
			ret.push_back(make_tuple(it - files.cbegin(), found.first, found.second));
	}
	return ret;
}

void print(ostream& os, vector<matches>& v, const string& book) {
	for (auto it = v.cbegin(); it != v.cend(); ++it) {
		os << "store #" << get<0>(*it) << ": " << accumulate(get<1>(*it), get<2>(*it), Sales_data(book)) << endl;
	}
}

int main() {
	vector<vector<Sales_data>> files = {
		{Sales_data("1234", 10, 20), Sales_data("2345", 10, 20)},
		{Sales_data("1234", 10, 20), Sales_data("1234", 10, 20)},
		{Sales_data("1234", 10, 20)}
	};
	string currBook = "1234";
	auto ret = findBook(files, currBook);
	print(cout, ret, currBook);
	return 0;
}