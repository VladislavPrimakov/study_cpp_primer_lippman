#include "TextQuery.h"


void TextQuery::buildMap(string& line, size_t& line_no) {
	data->push_back(line);
	istringstream lineStream(line);
	string word;
	while (lineStream >> word) {
		string word_no_punct;
		word_no_punct.reserve(word.size());
		copy_if(word.begin(), word.end(), back_inserter(word_no_punct), [](char& c) { return !ispunct(c); });
		if (word_no_punct.size()) {
			wm->insert({word_no_punct, make_shared<vector<size_t>>()}).first->second->push_back(line_no);
		}
	}
}

TextQuery::TextQuery(ifstream& infile) : data(make_shared<vector<string>>()), wm(make_shared<map<string, shared_ptr<vector<size_t>>>>()) {
	string line;
	size_t line_no = 0;
	while (getline(infile, line)) {
		buildMap(line, line_no);
		++line_no;
	}
}

QueryResult TextQuery::query(string& s) {
	auto it = wm->find(s);
	if (it == wm->end()) {
		return QueryResult(data, make_shared<vector<size_t>>(), s);
	} else {
		return QueryResult(data, it->second, s);
	}
}

QueryResult::QueryResult(shared_ptr<vector<string>> _data, shared_ptr<vector<size_t>> _lines, string s) : data(_data), lines(_lines), sought(s) {}

ostream& print(ostream& os, const QueryResult& qr) {
	if (qr.lines->size() == 0) {
		os << qr.sought + " occurs 0 times\n";
	} else {
		size_t sz = qr.lines->size();
		os << qr.sought + " occurs " + to_string(sz) + (sz == 1 ? " time\n" : " times\n");
		auto it_vec_unique_end = unique(qr.lines->begin(), qr.lines->end());
		for (auto iter = qr.lines->begin(); iter != it_vec_unique_end; ++iter) {
			os << "\t(line " + to_string(*iter + 1) + ") " + qr.data->at(*iter) + "\n";
		}
	}
	return os;
}

shared_ptr<vector<string>> QueryResult::getFile() {
	return data;
}


void runQueries(ifstream& infile) {
	TextQuery tq(infile);
	while (true) {
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q") break;
		print(cout, tq.query(s)) << endl;
	}
}