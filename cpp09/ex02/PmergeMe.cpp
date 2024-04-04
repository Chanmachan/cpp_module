//
// Created by chanma on 2023/10/16.
//

#include "PmergeMe.hpp"

std::vector<int> PmergeMe::inputVec(int ac, char **av) {
	std::vector<int> vec;
	for (int i = 0; i < ac; i++) {
		errno = 0;
		char *p_end;
		long l = std::strtol(av[i], &p_end, 10);
		if ((*p_end != '\0') || (errno == ERANGE) || (errno == EINVAL)) {
			throw std::invalid_argument("Invalid Arg");
		}
		vec.push_back((int)l);
	}
	return vec;
}

template<typename T>
void PmergeMe::mergeInsertionSort(std::vector<T> data) {
	(void)data;
	return;
}
template<typename T>
void PmergeMe::mergeInsertionSort(std::list<T> data) {
	(void)data;
	return;
}
