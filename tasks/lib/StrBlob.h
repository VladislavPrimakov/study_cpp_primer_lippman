#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

class StrBlob;

class StrBlobPtr {
	friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator<(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator>(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator>=(const StrBlobPtr&, const StrBlobPtr&);
	friend ostream& operator<<(ostream&, const StrBlobPtr&);
public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob& a, size_t sz = 0);
	string& deref() const;
	StrBlobPtr& incr();
	string& operator [](size_t);
	const string& operator [](size_t) const;
	StrBlobPtr& operator++();
	StrBlobPtr& operator--();
	StrBlobPtr operator++(int);
	StrBlobPtr operator--(int);
	StrBlobPtr operator+(size_t);
	StrBlobPtr& operator+=(size_t);
	StrBlobPtr operator-(size_t);
	StrBlobPtr& operator-=(size_t);
	string& operator*() const;
	string* operator->() const;
private:
	shared_ptr<vector<string>> check(size_t, const string&) const;
	weak_ptr<vector<string>> wptr;
	size_t curr;
};
ostream& operator<<(ostream&, const StrBlobPtr&);
bool operator==(const StrBlobPtr&, const StrBlobPtr&);
bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
bool operator<(const StrBlobPtr&, const StrBlobPtr&);
bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
bool operator>(const StrBlobPtr&, const StrBlobPtr&);
bool operator>=(const StrBlobPtr&, const StrBlobPtr&);


class StrBlob {
	friend class StrBlobPtr;
	friend bool operator==(const StrBlob&, const StrBlob&);
	friend bool operator!=(const StrBlob&, const StrBlob&);
	friend bool operator<(const StrBlob&, const StrBlob&);
	friend bool operator<=(const StrBlob&, const StrBlob&);
	friend bool operator>(const StrBlob&, const StrBlob&);
	friend bool operator>=(const StrBlob&, const StrBlob&);
	friend ostream& operator<<(ostream&, const StrBlob&);
public:
	StrBlob();
	StrBlob(initializer_list<string>);
	size_t size() const;
	bool empty() const;
	void push_back(const string&);
	void push_back(string&&);
	void pop_back();
	string& front();
	string& back();
	const string& front() const;
	const string& back() const;
	StrBlobPtr begin();
	StrBlobPtr end();
	string& operator [](size_t);
	const string& operator [](size_t) const;

private:
	shared_ptr<vector<string>> data;
	void check(size_t, const string&) const;
};

ostream& operator<<(ostream&, const StrBlob&);
bool operator==(const StrBlob&, const StrBlob&);
bool operator!=(const StrBlob&, const StrBlob&);
bool operator<(const StrBlob&, const StrBlob&);
bool operator<=(const StrBlob&, const StrBlob&);
bool operator>(const StrBlob&, const StrBlob&);
bool operator>=(const StrBlob&, const StrBlob&);