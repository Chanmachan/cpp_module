//
// Created by chanma on 2023/03/15.
//

#include "Span.hpp"
#include <iostream>
#include <algorithm>

Span::Span(unsigned int N): stored_len_(0), cap_(N) {

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
	}
	return *this;
}

void Span::addNumber(int num) {
	if (stored_len_ >= cap_) {
		throw std::runtime_error("Stotage has no more capacity");
	}
	storage.insert(num);
	stored_len_++;
}

std::multiset<int>::const_iterator Span::getBeginIterator() const {
	return storage.begin();
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
	std::multiset<int>::const_iterator itr_begin = storage.begin();
	unsigned int shortest_len = - *itr_begin + *++itr_begin;
	for (size_t i = 1; i < stored_len_ - 1; ++i) {
		unsigned int diff = - *itr_begin + *++itr_begin;
		shortest_len = diff < shortest_len ? diff : shortest_len;
	}
	return shortest_len;
}

unsigned int Span::longestSpan() const {
	if (stored_len_ < 2) {
		throw std::runtime_error("Insufficient storage space");
	}
	// endより一つ前が一番大きい値
	return *--storage.end() - *storage.begin();
}