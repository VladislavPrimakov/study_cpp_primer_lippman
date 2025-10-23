//Упражнение 11.14.Дополните карту фамилий семей и их детей,
//написанную для упражнения в разделе 11.2.1 (стр. 543), вектором пар, содержащих
//имя ребенка и день его рождения.

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using Fam = map<string, vector<pair<string, int>>>;

void add_family(Fam& fam, string& name) {
	if (!fam.contains(name)) {
		fam[name];
	}
}

void add_child(Fam& fam, string& fam_name, Fam::mapped_type::value_type child) {
	fam[fam_name].push_back(child);
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
	vector<string> fam_init = {"Fam1", "Fam2", "Fam1"};
	vector<vector<pair<string, int>>> childs_init = {{{"Child1", 1}, {"Child2", 2}}, {{"Child3", 3}, {"Child4", 4}}, {{"Child5", 5}, {"Child6", 6}}};
	for (size_t i = 0; i < fam_init.size(); i++) {
		add_family(families, fam_init[i]);
		for (auto& child_name : childs_init[i]) {
			add_child(families, fam_init[i], child_name);
		}
	}
	print_families(families);
	return 0;
}