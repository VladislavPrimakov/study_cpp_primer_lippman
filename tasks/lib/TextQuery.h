#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <sstream>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

class QueryResult;

class TextQuery {
	friend class QueryResult;
	shared_ptr<vector<string>> data;
	shared_ptr<map<string, shared_ptr<vector<size_t>>>> wm;
	void buildMap(string& line, size_t& line_no);
public:
	TextQuery(ifstream& infile);
	QueryResult query(string& s);
};

class QueryResult {
	shared_ptr<vector<string>> data;
	shared_ptr<vector<size_t>> lines;
	string sought;
private:
public:
	QueryResult(shared_ptr<vector<string>> _data, shared_ptr<vector<size_t>> _lines, string s);
	friend ostream& print(ostream& os, const QueryResult& qr);
	shared_ptr<vector<string>> getFile();
	vector<size_t>::iterator begin() {
		return lines->begin();
	}
	vector<size_t>::iterator end() {
		return lines->end();
	}
};

ostream& print(ostream& os, const QueryResult& qr);
void runQueries(ifstream& infile);