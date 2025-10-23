#ifndef STRVEC_H
#define STRVEC_H

#include <string>
#include <memory>
using namespace std;

class StrVec {
public:
	StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec&);
	StrVec(initializer_list<string>);
	StrVec(StrVec&& s) noexcept;
	StrVec& operator=(const StrVec&);
	~StrVec();
	void push_back(const string&);
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

#endif // STRVEC_H