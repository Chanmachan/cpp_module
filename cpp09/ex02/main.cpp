//
// Created by chanma on 2023/10/16.
//

#include <iostream>
#include "PmergeMe.hpp"

std::vector<int> inputVec(int ac, char **av) {
	std::vector<int> vec;
	for (int i = 0; i < ac; i++) {
		errno = 0;
		char *p_end;
		long l = std::strtol(av[i], &p_end, 10);
		if ((p_end != '\0') || (errno == ERANGE) || (errno == EINVAL)) {
			throw std::invalid_argument("Invalid Arg");
		}
		vec.push_back((int)l);
	}
	return vec;
}

int main(int ac, char **av) {
	if (ac <= 1) {
		std::cout << "Error: " << "Lack of Args" << std::endl;
		return 1;
	}
	for (int i = 0; i < ac; i++) {
		std::cout << av[i] << std::endl;
	}
	PmergeMe pmergeMe;


	PmergeMe::mergeInsertionSort(data);


	return 0;
}
