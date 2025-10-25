#ifndef BLOB_H
#define BLOB_H

#include <iostream>
#include <ostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

template <typename T> class Blob;

template<typename T>
class BlobPtr {
	friend bool operator== <T>(const BlobPtr&, const BlobPtr&);
	friend bool operator!= <T>(const BlobPtr&, const BlobPtr&);
	friend bool operator< <T>(const BlobPtr&, const BlobPtr&);
	friend bool operator<= <T>(const BlobPtr&, const BlobPtr&);
	friend bool operator> <T>(const BlobPtr&, const BlobPtr&);
	friend bool operator>= <T>(const BlobPtr&, const BlobPtr&);
	friend ostream& operator<< <T>(ostream&, const BlobPtr&);
public:
	typedef T value_type;
	BlobPtr() : curr(0) {}
	BlobPtr(Blob<T>& a, size_t sz = 0);
	T& deref() const;
	BlobPtr& incr();
	T& operator [](size_t);
	const T& operator [](size_t) const;
	BlobPtr& operator++();
	BlobPtr& operator--();
	BlobPtr operator++(int);
	BlobPtr operator--(int);
	BlobPtr operator+(size_t);
	BlobPtr& operator+=(size_t);
	BlobPtr operator-(size_t);
	BlobPtr& operator-=(size_t);
	T& operator*() const;
	T* operator->() const;
private:
	shared_ptr<vector<T>> check(size_t, const string&) const;
	weak_ptr<vector<T>> wptr;
	size_t curr;
};


template<typename T>
class Blob {
	friend class BlobPtr<T>;
	friend bool operator== <T>(const Blob&, const Blob&);
	friend bool operator!= <T>(const Blob&, const Blob&);
	friend bool operator< <T>(const Blob&, const Blob&);
	friend bool operator<= <T>(const Blob&, const Blob&);
	friend bool operator> <T>(const Blob&, const Blob&);
	friend bool operator>= <T>(const Blob&, const Blob&);
	friend ostream& operator<< <T>(ostream&, const Blob&);

	shared_ptr<vector<T>> data;
	void check(size_t, const string&) const;
public:
	typedef T value_type;
	Blob();
	Blob(initializer_list<T>);
	template <typename It> Blob(It b, It e);
	size_t size() const;
	bool empty() const;
	void push_back(const T&);
	void push_back(T&&);
	void pop_back();
	T& front();
	T& back();
	const T& front() const;
	const T& back() const;
	BlobPtr<T> begin();
	BlobPtr<T> end();
	T& operator [](size_t);
	const T& operator [](size_t) const;
};

template<typename T>
Blob<T>::Blob() : data(make_shared<vector<T>>()) {}

template<typename T>
Blob<T>::Blob(initializer_list<T> il) : data(make_shared<vector<T>>(il)) {}

template<typename T>
template<typename It>
Blob<T>::Blob(It b, It e) : data(make_shared<vector<T>>(b, e)) {}


template<typename T>
void Blob<T>::check(size_t i, const string& msg) const {
	if (i >= data->size())
		throw out_of_range(msg);
}

template<typename T>
size_t Blob<T>::size() const {
	return data->size();
}

template<typename T>
bool Blob<T>::empty() const {
	return data->empty();
}

template<typename T>
void Blob<T>::push_back(const T& s) {
	data->push_back(s);
}

template<typename T>
void Blob<T>::push_back(T&& s) {
	data->push_back(s);
}

template<typename T>
BlobPtr<T> Blob<T>::begin() {
	return BlobPtr<T>(*this);
}

template<typename T>
BlobPtr<T> Blob<T>::end() {
	return BlobPtr<T>(*this, data->size());
}

template<typename T>
T& Blob<T>::front() {
	check(0, "front on empty Blob");
	return data->front();
}

template<typename T>
T& Blob<T>::back() {
	check(data->size() - 1, "back on empty Blob");
	return data->back();
}

template<typename T>
const T& Blob<T>::front() const {
	check(0, "front on empty Blob");
	return data->front();
}

template<typename T>
const T& Blob<T>::back() const {
	check(data->size() - 1, "back on empty Blob");
	return data->back();
}

template<typename T>
void Blob<T>::pop_back() {
	check(data->size() - 1, "pop_back on empty Blob");
	data->pop_back();
}

template<typename T>
T& Blob<T>::operator [](size_t i) {
	return (*data)[i];
}

template<typename T>
const T& Blob<T>::operator [](size_t i) const {
	return data->at(i);
}

template<typename T>
ostream& operator<<(ostream& os, const Blob<T>& item) {
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

template<typename T>
bool operator==(const Blob<T>& l, const Blob<T>& r) {
	return *(l.data) == *(r.data);
}

template<typename T>
bool operator!=(const Blob<T>& l, const Blob<T>& r) {
	return !(l == r);
}

template<typename T>
bool operator<(const Blob<T>& l, const Blob<T>& r) {
	return *(l.data) < *(r.data);
}

template<typename T>
bool operator<=(const Blob<T>& l, const Blob<T>& r) {
	return *(l.data) <= *(r.data);
}

template<typename T>
bool operator>(const Blob<T>& l, const Blob<T>& r) {
	return *(l.data) > *(r.data);
}

template<typename T>
bool operator>=(const Blob<T>& l, const Blob<T>& r) {
	return *(l.data) >= *(r.data);
}

template<typename T>
BlobPtr<T>::BlobPtr(Blob<T>& a, size_t sz) : wptr(a.data), curr(sz) {}

template<typename T>
shared_ptr<vector<T>> BlobPtr<T>::check(size_t i, const string& msg) const {
	auto ret = wptr.lock();
	if (!ret)
		throw runtime_error("unbound Blob");
	if (i >= ret->size())
		throw out_of_range(msg);
	return ret;
}

template<typename T>
T& BlobPtr<T>::deref() const {
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::incr() {
	check(curr, "increment past end of Blob");
	++curr;
	return *this;
}

template<typename T>
T& BlobPtr<T>::operator [](size_t i) {
	return (*check(i, "get element at index" + to_string(i)))[i];
}

template<typename T>
const T& BlobPtr<T>::operator [](size_t i) const {
	return (*check(i, "get element at index" + to_string(i))).at(i);
}

template<typename T>
ostream& operator<<(ostream& os, const BlobPtr<T>& sbp) {
	os << sbp.deref();
	return os;
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator++() {
	check(curr, "increment past end of Blob");
	++curr;
	return *this;
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator--() {
	check(--curr, "decrement past begin of Blob");
	return *this;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator++(int) {
	BlobPtr<T> ret = *this;
	++*this;
	return ret;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator--(int) {
	BlobPtr<T> ret = *this;
	--*this;
	return ret;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator+(size_t i) {
	BlobPtr<T> res(*this);
	res.curr += i;
	return res;
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator+=(size_t i) {
	curr += i;
	check(curr, "addition pointer of Blob");
	return *this;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator-(size_t i) {
	BlobPtr<T> res(*this);
	res.curr -= i;
	return res;
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator-=(size_t i) {
	curr -= i;
	check(curr, "subtraction pointer of Blob");
	return *this;
}

template<typename T>
T& BlobPtr<T>::operator*() const {
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

template<typename T>
T* BlobPtr<T>::operator->() const {
	return &this->operator*();
}

template<typename T>
bool operator==(const BlobPtr<T>& l, const BlobPtr<T>& r) {
	return l.deref() == r.deref();
}

template<typename T>
bool operator!=(const BlobPtr<T>& l, const BlobPtr<T>& r) {
	return !(l == r);
}

template<typename T>
bool operator<(const BlobPtr<T>& l, const BlobPtr<T>& r) {
	return l.deref() < r.deref();
}

template<typename T>
bool operator<=(const BlobPtr<T>& l, const BlobPtr<T>& r) {
	return l.deref() <= r.deref();
}

template<typename T>
bool operator>(const BlobPtr<T>& l, const BlobPtr<T>& r) {
	return l.deref() > r.deref();
}

template<typename T>
bool operator>=(const BlobPtr<T>& l, const BlobPtr<T>& r) {
	return l.deref() >= r.deref();
}

#endif // !BLOB_H
