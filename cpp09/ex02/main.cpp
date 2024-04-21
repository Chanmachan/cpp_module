//
// Created by chanma on 2023/10/16.
//

#include <iostream>
#include "PmergeMe.hpp"
#include <ctime>
#include <iomanip>

int main(int ac, char **av) {
	if (ac <= 1) {
		std::cout << "Error: " << "Lack of Args" << std::endl;
		return 1;
	}

	/*
	 * テンプレートテンプレートパラメータを使用しているため
	 * コンパイラが自動で型を推測できないので
	 * それらの関数を呼び出すためには関数呼び出し時に明治的に型を指定する必要がある
	 */

	// vector part
	{
		std::vector<int> vec;

		PmergeMe::inputToContainer(ac, av, vec);
		clock_t start = clock();
		vec = PmergeMe::mergeInsertionSort<int, std::vector>(vec);
		clock_t end = clock();

		std::cout << std::endl;
		double elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
		std::cout << "Time to process a range of " << std::setw(4) << vec.size() << " elements with std::vector :\t" \
					<< elapsed << " us" << std::endl;
	}
	// list part
	{
		std::list<int> lst;

		PmergeMe::inputToContainer(ac, av, lst);
		clock_t start = clock();
		lst = PmergeMe::mergeInsertionSort<int, std::list>(lst);
		clock_t end = clock();

		std::cout << std::endl;
		double elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
		std::cout << "Time to process a range of " << std::setw(4) << lst.size() << " elements with std::list :\t" \
					<< elapsed << " us" << std::endl;
	}

	return 0;
}
