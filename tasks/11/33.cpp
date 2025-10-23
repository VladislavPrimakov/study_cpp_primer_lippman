//Упражнение 11.33.Реализуйте собственную версию программы
//преобразования слов.

#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <iostream>
using namespace std;

map<string, string> build_transform(istream& input) {
	map<string, string> transform;
	string s, key, value;
	while (input >> key && getline(input, value)) {
		if (value.size() && value[0] == ' ') {
			transform.insert({key, value.substr(1)});
		}
	}
	return transform;
}

stringstream read_text(istream& input) {
	stringstream ss;
	ss << input.rdbuf();
	return ss;
}

stringstream transform(map<string, string>& m, stringstream& text) {
	string line;
	stringstream ss_new;
	while (getline(text, line)) {
		stringstream ss_line(line);
		string word;
		bool first_word = false;
		while (ss_line >> word) {
			if (!first_word) {
				first_word = true;
			} else {
				ss_new << " ";
			}
			auto it = m.find(word);
			if (it != m.end()) {
				ss_new << it->second;
			} else {
				ss_new << word;
			}
		}
		ss_new << "\n";
	}
	return ss_new;
}


int main(int argc, char* argv[]) {
	if (argc < 3) {
		cerr << "Usage " << argv[0] << " <transform_file> <text_file>" << endl;
		return -1;
	}
	ifstream transform_file(argv[1]);
	if (!transform_file.is_open()) {
		cerr << "Fail open " << argv[1] << endl;
		return -1;
	}
	ifstream text_file(argv[2]);
	if (!text_file.is_open()) {
		cerr << "Fail open " << argv[2] << endl;
		return -1;
	}
	auto m = build_transform(transform_file);
	auto text = read_text(text_file);
	auto ss = transform(m, text);
	cout << ss.rdbuf();
	return 0;
}