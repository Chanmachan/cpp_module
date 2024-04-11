//
// Created by chanma on 2023/10/16.
//

#ifndef EXE_PMERGEME_HPP
#define EXE_PMERGEME_HPP

#include<vector>
#include <list>
#include "PairComparisonResult.hpp"

class PmergeMe {
private:

public:
	static std::vector<int> inputVec(int ac, char **av);
	template<typename T>
	static std::vector<T> mergeInsertionSort(std::vector<T> data);
//	template<typename T>
//	static void mergeInsertionSort(std::list<T> data);
};

// 定義を読み込む
#include "PmergeMe.tpp"

#endif //EXE_PMERGEME_HPP
