//
// Created by chanma on 2024/08/18.
//

#include "IteratorsGroup.hpp"
#include <iostream>

template<typename Iterator>
IteratorsGroup<Iterator>::IteratorsGroup() {

}

template<typename Iterator>
IteratorsGroup<Iterator>::IteratorsGroup(Iterator lhs, Iterator rhs): start(lhs), end(rhs) {

}

template<typename Iterator>
IteratorsGroup<Iterator>::IteratorsGroup(const IteratorsGroup& src) {
	*this = src;
}

template<typename Iterator>
IteratorsGroup<Iterator> &IteratorsGroup<Iterator>::operator=(const IteratorsGroup &src) {
	if (this != &src) {
		start = src.start;
		end = src.end;
	}
	return *this;
}

template<typename Iterator>
IteratorsGroup<Iterator>::~IteratorsGroup() {

}

template<typename Iterator>
void IteratorsGroup<Iterator>::swap(IteratorsGroup<Iterator> &lhs, IteratorsGroup<Iterator> &rhs) {
	std::swap_ranges(lhs.start, lhs.end, rhs.start);
}

template<typename Iterator>
void IteratorsGroup<Iterator>::print() {
	for (Iterator it = start; it != end; it++) {
		std::cout << *it << ", ";
	}
	std::cout << std::endl;
}
