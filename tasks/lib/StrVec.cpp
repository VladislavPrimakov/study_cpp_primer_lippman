#include "StrVec.h"

size_t StrVec::size() const {
	return first_free - elements;
}

size_t StrVec::capacity() const {
	return cap - elements;
}

string* StrVec::begin() const {
	return elements;
}

string* StrVec::end() const {
	return first_free;
}

void StrVec::chk_n_alloc() {
	if (size() == capacity())
		reallocate();
}

void StrVec::push_back(const string& s) {
	chk_n_alloc();
	allocator_traits<decltype(alloc)>::construct(alloc, first_free, s);
	++first_free;
}

void StrVec::push_back(string&& s) {
	chk_n_alloc();
	allocator_traits<decltype(alloc)>::construct(alloc, first_free, s);
	++first_free;
}

pair<string*, string*> StrVec::alloc_n_copy(const string* b, const string* e) {
	auto data = allocator_traits<decltype(alloc)>::allocate(alloc, e - b);
	return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free() {
	if (elements) {
		for (auto p = first_free; p != elements; ) {
			--p;
			allocator_traits<decltype(alloc)>::destroy(alloc, p);
		}
		allocator_traits<decltype(alloc)>::deallocate(alloc, elements, cap - elements);
		elements = first_free = cap = nullptr;
	}
}

void StrVec::reallocate() {
	auto new_capacity = size() ? 2 * size() : 1;
	auto new_elements = allocator_traits<decltype(alloc)>::allocate(alloc, new_capacity);
	auto new_first_free = uninitialized_move(elements, first_free, new_elements);
	free();
	elements = new_elements;
	first_free = new_first_free;
	cap = elements + new_capacity;
}

StrVec::StrVec(const StrVec& s) {
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::StrVec(initializer_list<string> il) {
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::StrVec(StrVec&& s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap) {
	s.elements = s.first_free = s.cap = nullptr;
}

StrVec::~StrVec() {
	free();
}

StrVec& StrVec::operator=(StrVec&& rhs) noexcept {
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

StrVec& StrVec::operator=(const StrVec& rhs) {
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

StrVec& StrVec::operator=(initializer_list<string> il) {
	auto data = alloc_n_copy(il.begin(), il.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

string& StrVec::operator[](size_t n) {
	return elements[n];
}

const string& StrVec::operator[](size_t n) const {
	return elements[n];
}

ostream& operator<<(ostream& os, const StrVec& v) {
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


bool operator==(const StrVec& l, const StrVec& r) {
	if (l.size() != r.size()) {
		return false;
	}
	for (auto pl = l.begin(), pr = r.begin(); pl != l.end() || pr != r.end(); ++pl, ++pr) {
		if (*pl != *pr) {
			return false;
		}
	}
	return true;
}

bool operator!=(const StrVec& l, const StrVec& r) {
	return !(l == r);
}

bool operator<(const StrVec& l, const StrVec& r) {
	if (l.size() != r.size()) {
		return false;
	}
	for (auto pl = l.begin(), pr = r.begin(); pl != l.end() || pr != r.end(); ++pl, ++pr) {
		if (*pl >= *pr) {
			return false;
		}
	}
	return true;
}

bool operator<=(const StrVec& l, const StrVec& r) {
	if (l.size() != r.size()) {
		return false;
	}
	for (auto pl = l.begin(), pr = r.begin(); pl != l.end() || pr != r.end(); ++pl, ++pr) {
		if (*pl > *pr) {
			return false;
		}
	}
	return true;
}

bool operator>(const StrVec& l, const StrVec& r) {
	if (l.size() != r.size()) {
		return false;
	}
	for (auto pl = l.begin(), pr = r.begin(); pl != l.end() || pr != r.end(); ++pl, ++pr) {
		if (*pl <= *pr) {
			return false;
		}
	}
	return true;
}

bool operator>=(const StrVec& l, const StrVec& r) {
	if (l.size() != r.size()) {
		return false;
	}
	for (auto pl = l.begin(), pr = r.begin(); pl != l.end() || pr != r.end(); ++pl, ++pr) {
		if (*pl < *pr) {
			return false;
		}
	}
	return true;
}