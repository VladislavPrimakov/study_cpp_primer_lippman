#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

class StrBlob;

class StrBlobPtr {
public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob& a, size_t sz = 0);
	string& deref() const;
	StrBlobPtr& incr();
	bool operator==(const StrBlobPtr& other) const;
private:
	shared_ptr<vector<string>> check(size_t, const string&) const;
	weak_ptr<vector<string>> wptr;
	size_t curr;
};

class StrBlob {
	friend class StrBlobPtr;
public:
	StrBlob();
	StrBlob(initializer_list<string> il);
	size_t size() const;
	bool empty() const;
	void push_back(const string& t);
	void pop_back();
	string& front();
	string& back();
	const string& front() const;
	const string& back() const;
	StrBlobPtr begin();
	StrBlobPtr end();
private:
	shared_ptr<vector<string>> data;
	void check(size_t i, const string& msg) const;
};