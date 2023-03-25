//
// Created by chanma on 2023/03/15.
//

#include "Span.hpp"
#include <algorithm>
#include <climits>

typedef std::multiset<int>::const_iterator const_iterator;

Span::Span(unsigned int N): stored_len_(0), cap_(N), shortest_(UINT_MAX), longest_(UINT_MAX) {

}

Span::Span(const Span &src) {
	*this = src;
}

Span::~Span() {

}

Span &Span::operator=(const Span &src) {
	if (this != &src) {
		storage = src.storage;
		stored_len_ = src.stored_len_;
		cap_ = src.cap_;
		shortest_ = src.shortest_;
		longest_ = src.longest_;
	}
	return *this;
}

void Span::addNumber(int num) {
	if (stored_len_ >= cap_) {
		throw std::runtime_error("Storage has no more capacity");
	}
	stored_len_++;
	const_iterator iLower = storage.lower_bound(num);
	// lower_boundでイテレーターを返す (storageの中身<numにならない最初のところ->{1, 2, 5}<num(3)だったら5)
	// 要素が２個しかないうちはshortest_はかえない
	if (iLower != storage.end()) {
		unsigned int tmp_shortest = static_cast<unsigned int>(*iLower) - num;
		shortest_ = std::min(shortest_, tmp_shortest);
	}
	if (iLower != storage.begin()) {
		unsigned int tmp_shortest = static_cast<unsigned int>(num) - *--iLower;
		shortest_ = std::min(shortest_, tmp_shortest);
	}
	storage.insert(num);
	longest_ = *--storage.end() - *storage.begin();
}

const_iterator Span::getBeginIterator() const {
	return storage.begin();
}

const_iterator Span::getEndIterator() const {
	return storage.end();
}

unsigned int Span::getStoredLen() const {
	return stored_len_;
}

unsigned int Span::getCap() const {
	return cap_;
}

unsigned int Span::shortestSpan() const {
	if (stored_len_ < 2) {
		throw std::runtime_error("Insufficient storage space");
	}
	return shortest_;
}

unsigned int Span::longestSpan() const {
	if (stored_len_ < 2) {
		throw std::runtime_error("Insufficient storage space");
	}
	return longest_;
}