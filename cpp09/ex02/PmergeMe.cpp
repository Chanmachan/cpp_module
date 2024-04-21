//
// Created by chanma on 2024/04/10.
//

#include "PmergeMe.hpp"

void PmergeMe::inputToContainer(int ac, char **av, std::vector<int>& dst) {
	for (int i = 1; i < ac; i++) {
		errno = 0;
		char *p_end;
		long l = std::strtol(av[i], &p_end, 10);
		if ((*p_end != '\0') || (errno == ERANGE) || (errno == EINVAL)) {
			throw std::invalid_argument("Invalid Arg");
		}
		dst.push_back((int)l);
	}
}

void PmergeMe::inputToContainer(int ac, char **av, std::list<int>& dst) {
	for (int i = 1; i < ac; i++) {
		errno = 0;
		char *p_end;
		long l = std::strtol(av[i], &p_end, 10);
		if ((*p_end != '\0') || (errno == ERANGE) || (errno == EINVAL)) {
			throw std::invalid_argument("Invalid Arg");
		}
		dst.push_back((int)l);
	}
}
