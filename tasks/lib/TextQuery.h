#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

class QueryResult;

class TextQuery {
	friend class QueryResult;
	shared_ptr<vector<string>> data;
	shared_ptr<map<string, shared_ptr<vector<size_t>>>> wm;
	void buildMap(string& line, size_t& line_no);
public:
	TextQuery(ifstream&);
	TextQuery(stringstream&);
	QueryResult query(const string& s) const;
};

class QueryResult {
	friend ostream& print(ostream& os, const QueryResult& qr);

	shared_ptr<vector<string>> data;
	shared_ptr<vector<size_t>> lines;
	string sought;
public:
	QueryResult(shared_ptr<vector<string>> _data, shared_ptr<vector<size_t>> _lines, string s);
	shared_ptr<vector<string>> getFile();
	auto begin() {
		return lines->begin();
	}
	auto end() {
		return lines->end();
	}
};

ostream& print(ostream& os, const QueryResult& qr);
void runQueries(ifstream& infile);


class Query_base {
	friend class Query;
protected:
	virtual ~Query_base() = default;
private:
	virtual QueryResult eval(const TextQuery&) const = 0;
	virtual string rep() const = 0;
};

class WordQuery : public Query_base {
	friend class Query;
protected:
	string query_word;
public:
	WordQuery(const string& s) : query_word(s) {}
	QueryResult eval(const TextQuery& t) const;
	string rep() const {
		return query_word;
	}
};

class Query {
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
protected:
	Query(shared_ptr<Query_base> query) : q(query) {}
	shared_ptr<Query_base> q;
public:
	Query(const string& s) : q(new WordQuery(s)) {}
	QueryResult eval(const TextQuery&) const;
	string rep() const;
};


class NotQuery : public Query_base {
	friend Query operator~(const Query&);
protected:
	Query query;
public:
	NotQuery(const Query& q) : query(q) {}
	string rep() const {
		return "~(" + query.rep() + ")";
	}
	QueryResult eval(const TextQuery&) const;
};

inline Query operator~(const Query& operand) {
	return shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery : public Query_base {
protected:
	Query lhs, rhs;
	string opSym;
public:
	BinaryQuery(const Query& l, const Query& r, string s) : lhs(l), rhs(r), opSym(s) {}
	string rep() const {
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ") ";
	}
};

class AndQuery : public BinaryQuery {
	friend Query operator&(const Query&, const Query&);
public:
	AndQuery(const Query& left, const Query& right) : BinaryQuery(left, right, "&") {}
	QueryResult eval(const TextQuery&) const;
};

inline Query operator&(const Query& lhs, const Query& rhs) {
	return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

class OrQuery : public BinaryQuery {
	friend Query operator|(const Query&, const Query&);
public:
	OrQuery(const Query& left, const Query& right) : BinaryQuery(left, right, "|") {}
	QueryResult eval(const TextQuery&) const;
};

inline Query operator|(const Query& lhs, const Query& rhs) {
	return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}