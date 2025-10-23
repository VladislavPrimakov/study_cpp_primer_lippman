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

StrVec& StrVec::operator=(const StrVec& rhs) {
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

void StrVec::reallocate() {
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = allocator_traits<decltype(alloc)>::allocate(alloc, newcapacity);
	auto dest = uninitialized_move(elements, first_free, newdata);
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

