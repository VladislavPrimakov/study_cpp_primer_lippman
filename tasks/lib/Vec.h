#ifndef Vec_H
#define Vec_H

#include <string>
#include <memory>
#include <iostream>
using namespace std;

template <typename T>
class Vec {
	friend ostream& operator<< <T>(ostream&, const Vec&);
	friend bool operator== <T>(const Vec&, const Vec&);
	friend bool operator!= <T>(const Vec&, const Vec&);
	friend bool operator< <T>(const Vec&, const Vec&);
	friend bool operator<= <T>(const Vec&, const Vec&);
	friend bool operator> <T>(const Vec&, const Vec&);
	friend bool operator>= <T>(const Vec&, const Vec&);
public:
	Vec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
	Vec(const Vec&);
	Vec(initializer_list<T>);
	Vec(Vec&& s) noexcept;
	~Vec();
	Vec& operator=(Vec&&) noexcept;
	Vec& operator=(const Vec&);
	Vec& operator=(initializer_list<T>);
	T& operator[](size_t);
	const T& operator[](size_t) const;
	void push_back(const T&);
	void push_back(T&&);
	template <typename... Args> void emplace_back(Args&&...);
	size_t size() const;
	size_t capacity() const;
	T* begin() const;
	T* end() const;
private:
	allocator<T> alloc;
	void chk_n_alloc();
	pair<T*, T*> alloc_n_copy(const T*, const T*);
	void free();
	void reallocate();
	T* elements;
	T* first_free;
	T* cap;
};

template <typename T>
size_t Vec<T>::size() const {
	return first_free - elements;
}

template <typename T>
size_t Vec<T>::capacity() const {
	return cap - elements;
}

template <typename T>
T* Vec<T>::begin() const {
	return elements;
}

template <typename T>
T* Vec<T>::end() const {
	return first_free;
}

template <typename T>
void Vec<T>::chk_n_alloc() {
	if (size() == capacity())
		reallocate();
}

template <typename T>
void Vec<T>::push_back(const T& s) {
	chk_n_alloc();
	allocator_traits<decltype(alloc)>::construct(alloc, first_free, s);
	++first_free;
}

template <typename T>
void Vec<T>::push_back(T&& s) {
	chk_n_alloc();
	allocator_traits<decltype(alloc)>::construct(alloc, first_free, move(s));
	++first_free;
}

template <typename T>
template <typename... Args>
void Vec<T>::emplace_back(Args&&... args) {
	chk_n_alloc();
	allocator_traits<decltype(alloc)>::construct(alloc, first_free, forward<Args>(args)...);
	++first_free;
}


template <typename T>
pair<T*, T*> Vec<T>::alloc_n_copy(const T* b, const T* e) {
	auto data = allocator_traits<decltype(alloc)>::allocate(alloc, e - b);
	return {data, uninitialized_copy(b, e, data)};
}

template <typename T>
void Vec<T>::free() {
	if (elements) {
		for (auto p = first_free; p != elements; ) {
			--p;
			allocator_traits<decltype(alloc)>::destroy(alloc, p);
		}
		allocator_traits<decltype(alloc)>::deallocate(alloc, elements, cap - elements);
		elements = first_free = cap = nullptr;
	}
}

template <typename T>
void Vec<T>::reallocate() {
	auto new_capacity = size() ? 2 * size() : 1;
	auto new_elements = allocator_traits<decltype(alloc)>::allocate(alloc, new_capacity);
	auto new_first_free = uninitialized_move(elements, first_free, new_elements);
	free();
	elements = new_elements;
	first_free = new_first_free;
	cap = elements + new_capacity;
}

template <typename T>
Vec<T>::Vec(const Vec& s) {
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

template <typename T>
Vec<T>::Vec(initializer_list<T> il) {
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

template <typename T>
Vec<T>::Vec(Vec&& s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap) {
	s.elements = s.first_free = s.cap = nullptr;
}

template <typename T>
Vec<T>::~Vec() {
	free();
}

template <typename T>
Vec<T>& Vec<T>::operator=(Vec&& rhs) noexcept {
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

template <typename T>
Vec<T>& Vec<T>::operator=(const Vec& rhs) {
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

template <typename T>
Vec<T>& Vec<T>::operator=(initializer_list<T> il) {
	auto data = alloc_n_copy(il.begin(), il.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

template <typename T>
T& Vec<T>::operator[](size_t n) {
	return elements[n];
}

template <typename T>
const T& Vec<T>::operator[](size_t n) const {
	return elements[n];
}

template <typename T>
ostream& operator<<(ostream& os, const Vec<T>& v) {
	os << "[";
	for (size_t i = 0; i != v.size(); ++i) {
		os << *(v.begin() + i);
		if (i != v.size() - 1) {
			os << ", ";
		}
	}
	os << "]";
	return os;
}


template <typename T>
bool operator==(const Vec<T>& l, const Vec<T>& r) {
	if (l.size() != r.size()) {
		return false;
	}
	for (auto pl = l.begin(), pr = r.begin(); pl != l.end() && pr != r.end(); ++pl, ++pr) {
		if (*pl != *pr) {
			return false;
		}
	}
	return true;
}

template <typename T>
bool operator!=(const Vec<T>& l, const Vec<T>& r) {
	return !(l == r);
}

template <typename T>
bool operator<(const Vec<T>& l, const Vec<T>& r) {
	if (l.size() != r.size()) {
		return false;
	}
	for (auto pl = l.begin(), pr = r.begin(); pl != l.end() && pr != r.end(); ++pl, ++pr) {
		if (*pl >= *pr) {
			return false;
		}
	}
	return true;
}

template <typename T>
bool operator<=(const Vec<T>& l, const Vec<T>& r) {
	if (l.size() != r.size()) {
		return false;
	}
	for (auto pl = l.begin(), pr = r.begin(); pl != l.end() && pr != r.end(); ++pl, ++pr) {
		if (*pl > *pr) {
			return false;
		}
	}
	return true;
}

template <typename T>
bool operator>(const Vec<T>& l, const Vec<T>& r) {
	if (l.size() != r.size()) {
		return false;
	}
	for (auto pl = l.begin(), pr = r.begin(); pl != l.end() && pr != r.end(); ++pl, ++pr) {
		if (*pl <= *pr) {
			return false;
		}
	}
	return true;
}

template <typename T>
bool operator>=(const Vec<T>& l, const Vec<T>& r) {
	if (l.size() != r.size()) {
		return false;
	}
	for (auto pl = l.begin(), pr = r.begin(); pl != l.end() && pr != r.end(); ++pl, ++pr) {
		if (*pl < *pr) {
			return false;
		}
	}
	return true;
}
#endif // Vec_H