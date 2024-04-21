//
// Created by chanma on 2023/10/16.
//

#include <iostream>
#include "PmergeMe.hpp"
#include <ctime>
#include <iomanip>

std::ostream& operator<<(std::ostream& os, char** args) {
	for (size_t i = 1; args[i] != NULL; ++i) { // NOLINT(*-use-nullptr)
		os << args[i] << " ";
	}
	return os;
}

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
	PmergeMe pmergeMe;
	double elapsedVec;
	double elapsedLst;
	// vector part
	{
		std::vector<int> vec;

		pmergeMe.inputToContainer(ac, av, vec);
		clock_t start = clock();
		pmergeMe.mergeInsertionSort<int, std::vector>(vec);
		clock_t end = clock();


		elapsedVec = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	}
	// list part
	{
		std::list<int> lst;

		pmergeMe.inputToContainer(ac, av, lst);
		clock_t start = clock();
		pmergeMe.mergeInsertionSort<int, std::list>(lst);
		clock_t end = clock();

		elapsedLst = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	}

	// 出力
	std::cout << "Before:\t" << av << std::endl;
	std::cout << "After:\t" << pmergeMe.getVec() << std::endl;
	std::cout << "Time to process a range of " << std::setw(4) << pmergeMe.getVec() << " elements with std::vector :\t" \
					<< elapsedVec << " us" << std::endl;
	std::cout << "Time to process a range of " << std::setw(4) << pmergeMe.getLst() << " elements with std::list   :\t" \
					<< elapsedLst << " us" << std::endl;

	return 0;
}
