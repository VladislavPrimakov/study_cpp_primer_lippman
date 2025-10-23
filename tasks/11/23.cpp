//Упражнение 11.23.Перепишите карту, хранящую вектора имен детей с
//ключом в виде фамилии семьи из упражнений раздела 11.2.1 (стр. 543), так, чтобы
//использовался контейнер multimap.

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using Fam = multimap<string, vector<pair<string, int>>>;

void add_family(Fam& fam, string name) {
	fam.insert({name, Fam::mapped_type()});
}

void add_child(Fam& fam, string fam_name, Fam::mapped_type::value_type child, size_t num_fam) {
	auto its = fam.equal_range(fam_name);
	size_t i = 0;
	for (auto it = its.first; it != its.second; ++it, ++i)
		if (i == num_fam) {
			it->second.push_back(child);
		}
}

void print_families(const Fam& fam) {
	for (auto& f : fam) {
		cout << "Family: " << f.first << " has childs: ";
		for_each(f.second.cbegin(), f.second.cend(), [](Fam::mapped_type::value_type child) {cout << child.first << "(" << child.second << ") "; });
		cout << endl;
	}
}

int main() {
	Fam families;
	vector<vector<pair<string, int>>> childs_init = {{{"Child1", 1}, {"Child2", 2}}, {{"Child3", 3}, {"Child4", 4}}, {{"Child5", 5}, {"Child6", 6}}};
	add_family(families, "Fam1");
	add_family(families, "Fam2");
	add_family(families, "Fam1");
	add_child(families, "Fam1", {"Child1", 1}, 0);
	add_child(families, "Fam1", {"Child2", 2}, 0);
	add_child(families, "Fam2", {"Child3", 3}, 0);
	add_child(families, "Fam2", {"Child4", 4}, 0);
	add_child(families, "Fam1", {"Child5", 1}, 1);
	add_child(families, "Fam1", {"Child5", 1}, 1);

	print_families(families);
	return 0;
}