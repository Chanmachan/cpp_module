//
// Created by chanma on 2024/08/18.
//

#include "IteratorsGroup.hpp"
#include <iostream>

template<typename Iterator>
IteratorsGroup<Iterator>::IteratorsGroup() {

}

template<typename Iterator>
IteratorsGroup<Iterator>::IteratorsGroup(Iterator lhs, Iterator rhs, bool independent): start_(lhs), end_(rhs), isIndependent_(independent) {

}

template<typename Iterator>
IteratorsGroup<Iterator>::IteratorsGroup(const IteratorsGroup& src) {
	*this = src;
}

template<typename Iterator>
IteratorsGroup<Iterator> &IteratorsGroup<Iterator>::operator=(const IteratorsGroup &src) {
	if (this != &src) {
		start_ = src.start_;
		end_ = src.end_;
		isIndependent_ = src.isIndependent_;
	}
	return *this;
}

template<typename Iterator>
IteratorsGroup<Iterator>::~IteratorsGroup() {

}

template<typename Iterator>
void IteratorsGroup<Iterator>::swap(IteratorsGroup<Iterator> &lhs, IteratorsGroup<Iterator> &rhs) {
	std::swap_ranges(lhs.start_, lhs.end_, rhs.start_);
}

template<typename Iterator>
void IteratorsGroup<Iterator>::print() {
	for (Iterator it = start_; it != end_; it++) {
		std::cout << *it << ", ";
	}
	std::cout << std::endl;
}

template<typename Iterator>
bool IteratorsGroup<Iterator>::getIsIndependent() const {
	return isIndependent_;
}

template<typename Iterator>
Iterator IteratorsGroup<Iterator>::getStart() const {
	return start_;
}

template<typename Iterator>
Iterator IteratorsGroup<Iterator>::getEnd() const {
	return end_;
}

template<typename Iterator>
int IteratorsGroup<Iterator>::getStartValue() const {
	return *start_;
}

