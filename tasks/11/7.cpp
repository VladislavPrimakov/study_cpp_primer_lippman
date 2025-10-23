//Упражнение 11.7.Определите карту, ключ которой является фамилией
//семьи, а значение — вектором имен детей.Напишите код, способный
//добавлять новые семьи и новых детей в существующие семьи.

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using Fam = map<string, vector<string>>;

void add_family(Fam& fam, string& name) {
	if (!fam.contains(name)) {
		fam[name];
	}
}

void add_child(Fam& fam, string& fam_name, string& child_name) {
	fam[fam_name].push_back(child_name);
}

void print_families(const Fam& fam) {
	for (auto& f : fam) {
		cout << "Family: " << f.first << " has childs: ";
		for_each(f.second.cbegin(), f.second.cend(), [](string child) {cout << child << " "; });
		cout << endl;
	}
}

int main() {
	Fam families;
	vector<string> fam_init = {"Fam1", "Fam2", "Fam1"};
	vector<vector<string>> childs_init = {{"Child1", "Child2"}, {"Child3", "Child4"}, {"Child5", "Child6"}};
	for (size_t i = 0; i < fam_init.size(); i++) {
		add_family(families, fam_init[i]);
		for (auto& child_name : childs_init[i]) {
			add_child(families, fam_init[i], child_name);
		}
	}
	print_families(families);
	return 0;
}