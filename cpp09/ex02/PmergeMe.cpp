//
// Created by chanma on 2024/04/10.
//

#include "PmergeMe.hpp"
#include "utils.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) {
	*this = src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &src) {
	if (this != &src) {
		vec_ = src.vec_;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::inputToContainer(int ac, char **av, std::vector<int>& dst) {
	if (ac > 42000) {
		throw std::invalid_argument("too many args: max 42000");
	}
	for (int i = 1; i < ac; i++) {
		errno = 0;
		char *p_end;
		long l = std::strtol(av[i], &p_end, 10);
		if (*p_end != '\0' || errno == ERANGE || errno == EINVAL || \
			strlen(av[i]) > 11 || l <= 0 || l > 2147483647) {
			throw std::invalid_argument("Invalid Arg");
		}
		int value = (int)l;
		if (std::find(dst.begin(), dst.end(), value) != dst.end()) {
			throw std::invalid_argument("Duplicate value detected");
		}
		dst.push_back((int)l);
	}
}

void PmergeMe::mergeInsertionSort(std::vector<int>& data, int recursive_count) {
	int pow = powerOfTwo(recursive_count);
	if (data.size() / pow == 1) {
		return;
	}
	bool hasUnpairedElement = data.size() % pow != 0;
	(void )hasUnpairedElement;
	std::cout << "recursive[" << recursive_count << "] " << "bef: ";
	printVecRecursive(data, recursive_count);
	// ここに再帰処理する関数を作る

	for (size_t i = 0; i + pow < data.size(); i += 2 * pow) {
		if (data[i] < data[i + pow]) {
			std::swap(data[i], data[i + pow]);
		}
	}
	std::cout << "recursive[" << recursive_count << "] " << "aft: ";
	printVecRecursive(data, recursive_count);
	mergeInsertionSort(data, recursive_count + 1);
}

std::vector<int> PmergeMe::getVec() { return vec_; }


void PmergeMe::printVec(std::vector<int> v) {
	for (size_t i = 0; i < v.size(); i++) {
		std::cout << v[i] << ", ";
	}
	std::cout << std::endl;
}

void PmergeMe::printVecRecursive(std::vector<int> v, int recursive_count) {
	int pow = powerOfTwo(recursive_count);
	for (size_t i = 0; i + pow < v.size(); i++) {
		std::cout << v[i] << ", ";
		std::cout << v[i + pow] << ", ";
		i += pow;
	}
	std::cout << std::endl;
}
