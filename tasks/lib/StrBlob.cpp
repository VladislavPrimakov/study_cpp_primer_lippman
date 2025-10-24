#include "StrBlob.h"

StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}

StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

void StrBlob::check(size_t i, const string& msg) const {
	if (i >= data->size())
		throw out_of_range(msg);
}

size_t StrBlob::size() const {
	return data->size();
}

bool StrBlob::empty() const {
	return data->empty();
}

void StrBlob::push_back(const string& s) {
	data->push_back(s);
}

void StrBlob::push_back(string&& s) {
	data->push_back(s);
}

StrBlobPtr StrBlob::begin() {
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
	return StrBlobPtr(*this, data->size());
}

string& StrBlob::front() {
	check(0, "front on empty StrBlob");
	return data->front();
}
string& StrBlob::back() {
	check(data->size() - 1, "back on empty StrBlob");
	return data->back();
}

const string& StrBlob::front() const {
	check(0, "front on empty StrBlob");
	return data->front();
}
const string& StrBlob::back() const {
	check(data->size() - 1, "back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back() {
	check(data->size() - 1, "pop_back on empty StrBlob");
	data->pop_back();
}

string& StrBlob::operator [](size_t i) {
	return (*data)[i];
}

const string& StrBlob::operator [](size_t i) const {
	return data->at(i);
}


ostream& operator<<(ostream& os, const StrBlob& item) {
	os << "[";
	for (size_t i = 0; i != item.size(); ++i) {
		os << (*item.data)[i];
		if (i != item.size() - 1) {
			os << ", ";
		}
	}
	os << "]";
	return os;
}

bool operator==(const StrBlob& l, const StrBlob& r) {
	return *(l.data) == *(r.data);
}

bool operator!=(const StrBlob& l, const StrBlob& r) {
	return !(l == r);
}

bool operator<(const StrBlob& l, const StrBlob& r) {
	return *(l.data) < *(r.data);
}

bool operator<=(const StrBlob& l, const StrBlob& r) {
	return *(l.data) <= *(r.data);
}

bool operator>(const StrBlob& l, const StrBlob& r) {
	return *(l.data) > *(r.data);
}

bool operator>=(const StrBlob& l, const StrBlob& r) {
	return *(l.data) >= *(r.data);
}


StrBlobPtr::StrBlobPtr(StrBlob& a, size_t sz) : wptr(a.data), curr(sz) {}

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string& msg) const {
	auto ret = wptr.lock();
	if (!ret)
		throw runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw out_of_range(msg);
	return ret;
}

string& StrBlobPtr::deref() const {
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

string& StrBlobPtr::operator [](size_t i) {
	return (*check(i, "get element at index" + i))[i];
}
const string& StrBlobPtr::operator [](size_t i) const {
	return (*check(i, "get element at index" + i)).at(i);
}

ostream& operator<<(ostream& os, const StrBlobPtr& sbp) {
	os << sbp.deref();
	return os;
}

StrBlobPtr& StrBlobPtr::operator++() {
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr& StrBlobPtr::operator--() {
	check(--curr, "decrement past begin of StrBlobPtr");
	return *this;
}

StrBlobPtr StrBlobPtr::operator++(int) {
	StrBlobPtr ret = *this;
	++*this;
	return ret;
}

StrBlobPtr StrBlobPtr::operator--(int) {
	StrBlobPtr ret = *this;
	--*this;
	return ret;
}

StrBlobPtr StrBlobPtr::operator+(size_t i) {
	StrBlobPtr res(*this);
	res.curr += i;
	return res;
}

StrBlobPtr& StrBlobPtr::operator+=(size_t i) {
	curr += i;
	check(curr, "addition pointer of StrBlobPtr");
	return *this;
}

StrBlobPtr StrBlobPtr::operator-(size_t i) {
	StrBlobPtr res(*this);
	res.curr -= i;
	return res;
}

StrBlobPtr& StrBlobPtr::operator-=(size_t i) {
	curr -= i;
	check(curr, "subtraction pointer of StrBlobPtr");
	return *this;
}

string& StrBlobPtr::operator*() const {
	auto p = check(curr, "dereference past end");
	return (*p)[curr];

}
string* StrBlobPtr::operator->() const {
	return &this->operator*();
}

bool operator==(const StrBlobPtr& l, const StrBlobPtr& r) {
	return l.deref() == r.deref();
}

bool operator!=(const StrBlobPtr& l, const StrBlobPtr& r) {
	return !(l == r);
}

bool operator<(const StrBlobPtr& l, const StrBlobPtr& r) {
	return l.deref() < r.deref();
}

bool operator<=(const StrBlobPtr& l, const StrBlobPtr& r) {
	return l.deref() <= r.deref();
}

bool operator>(const StrBlobPtr& l, const StrBlobPtr& r) {
	return l.deref() > r.deref();
}

bool operator>=(const StrBlobPtr& l, const StrBlobPtr& r) {
	return l.deref() >= r.deref();
}