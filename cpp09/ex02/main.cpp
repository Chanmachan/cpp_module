//
// Created by chanma on 2023/10/16.
//

#include <iostream>
#include "PmergeMe.hpp"
#include "utils.hpp"
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
	std::vector<int> vec;
//	double elapsedLst;
	// vector part
	{
		try {
			vec = inputToContainer<std::vector<int> >(ac, av);
		} catch (std::invalid_argument& e) {
			std::cerr << "Error: " << e.what() << std::endl;
			return 1;
		}
		clock_t start = clock();
		pmergeMe.mergeInsertionSort(vec, vec.size(), 0);
		clock_t end = clock();

		elapsedVec = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	}
	// list part
//	{
//		std::list<int> lst;
//
//		try {
//			pmergeMe.inputToContainer(ac, av, lst);
//		} catch (std::invalid_argument& e) {
//			std::cerr << "Error: " << e.what() << std::endl;
//			return 1;
//		}
//		clock_t start = clock();
//		pmergeMe.mergeInsertionSort<int, std::list>(lst);
//		clock_t end = clock();
//
//		elapsedLst = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
//	}

	// 出力
	std::cout << "Before:\t" << av << std::endl;
	std::cout << "After:\t" << vec << std::endl;
#ifdef DEBUG
	if (std::is_sorted(vec.begin(), vec.end())) {
		std::cout << "The vector is sorted." << std::endl;
	} else {
		std::cout << "The vector is not sorted." << std::endl;
	}
#endif
	std::cout << "Time to process a range of " << std::setw(4) << pmergeMe.getVec().size() << " elements with std::vector :\t" \
					<< elapsedVec << " us" << std::endl;
//	std::cout << "Time to process a range of " << std::setw(4) << pmergeMe.getLst().size() << " elements with std::list   :\t" \
//					<< elapsedLst << " us" << std::endl;

	return 0;
}
