//
// Created by chanma on 2024/04/10.
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
