//
// Created by chanma on 2024/04/10.
//

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) {
	*this = src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &src) {
	if (this != &src) {
		vec_ = src.vec_;
		lst_ = src.lst_;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}