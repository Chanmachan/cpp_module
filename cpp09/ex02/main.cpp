//
// Created by chanma on 2023/10/16.
//

#include <iostream>
#include "PmergeMe.hpp"

int main(int ac, char **av) {
	if (ac <= 1) {
		std::cout << "Error: " << "Lack of Args" << std::endl;
		return 1;
	}
	for (int i = 0; i < ac; i++) {
		std::cout << av[i] << std::endl;
	}

	std::vector<int> vec;

	vec = PmergeMe::inputVec(ac, av);
	PmergeMe::mergeInsertionSort(vec);


	return 0;
}
