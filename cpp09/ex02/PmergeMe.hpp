//
// Created by chanma on 2023/10/16.
//

#ifndef EXE_PMERGEME_HPP
#define EXE_PMERGEME_HPP

#include <vector>
#include <list>
#include "PairComparisonResult.hpp"

class PmergeMe {
private:

public:
	static void inputToContainer(int ac, char **av, std::vector<int>& dst);
	static void inputToContainer(int ac, char **av, std::list<int>& dst);
	template<typename T, template<typename, typename=std::allocator<T> > class Container>
	static std::vector<T> mergeInsertionSort(std::vector<T> data);
	template<typename T, template<typename, typename=std::allocator<T> > class Container>
	static std::list<T> mergeInsertionSort(std::list<T> data);
	template<typename T>
	static typename std::list<T>::iterator lowerBoundForList(typename std::list<T>::iterator first, typename std::list<T>::iterator last, const T& value);
};

// 定義を読み込む
#include "PmergeMe.tpp"

#endif //EXE_PMERGEME_HPP
