#ifndef STRVEC_H
#define STRVEC_H

#include <string>
#include <memory>
#include <iostream>
using namespace std;

class StrVec {
	friend ostream& operator<<(ostream&, const StrVec&);
	friend bool operator==(const StrVec&, const StrVec&);
	friend bool operator!=(const StrVec&, const StrVec&);
	friend bool operator<(const StrVec&, const StrVec&);
	friend bool operator<=(const StrVec&, const StrVec&);
	friend bool operator>(const StrVec&, const StrVec&);
	friend bool operator>=(const StrVec&, const StrVec&);
public:
	StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec&);
	StrVec(initializer_list<string>);
	StrVec(StrVec&& s) noexcept;
	~StrVec();
	StrVec& operator=(StrVec&&) noexcept;
	StrVec& operator=(const StrVec&);
	StrVec& operator=(initializer_list<string>);
	string& operator[](size_t);
	const string& operator[](size_t) const;
	void push_back(const string&);
	void push_back(string&&);
	size_t size() const;
	size_t capacity() const;
	string* begin() const;
	string* end() const;
private:
	allocator<string> alloc;
	void chk_n_alloc();
	pair<string*, string*> alloc_n_copy(const string*, const string*);
	void free();
	void reallocate();
	string* elements;
	string* first_free;
	string* cap;
};

ostream& operator<<(ostream&, const StrVec&);
bool operator==(const StrVec&, const StrVec&);
bool operator!=(const StrVec&, const StrVec&);
bool operator<(const StrVec&, const StrVec&);
bool operator<=(const StrVec&, const StrVec&);
bool operator>(const StrVec&, const StrVec&);
bool operator>=(const StrVec&, const StrVec&);
#endif // STRVEC_H