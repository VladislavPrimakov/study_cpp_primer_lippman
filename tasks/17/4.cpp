
#include "Sales_data.h"
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
using namespace std;

using matches = tuple<vector<Sales_data>::size_type, vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator>;

vector<matches> findBook(const vector<vector<Sales_data>>& files, const string& book) {
	vector<matches> ret;
	for (auto it = files.cbegin(); it != files.cend(); ++it) {
		auto found = equal_range(it->cbegin(), it->cend(), book, [](Sales_data& s1, Sales_data& s2) {return s1.isbn == s2.isbn; });
		if (found.first != found.second)
			ret.push_back(make_tuple(it - files.cbegin(), found.first, found.second));
	}
	return ret;
}

void print(vector<matches>& v) {
	for (auto it = v.cbegin(); it != v.cend(); ++it) {
		cout << "file #" << get<0>(*it) << endl;
		for (auto it2 = get<1>(*it); it2 != get<2>(*it); ++it2) {
			cout << *it2 << endl;
		}
	}
}

int main() {
	vector<vector<Sales_data>> files = {{Sales_data("1234")}, {Sales_data("1234"), Sales_data("1234")}, {Sales_data("1234")}};
	string currBook = "1234";
	auto ret = findBook(files, currBook);
	print(ret);
	return 0;
}