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
	std::vector<int> vec_;
	std::list<int> lst_;
public:
	void inputToContainer(int ac, char **av, std::vector<int>& dst);
	void inputToContainer(int ac, char **av, std::list<int>& dst);
	template<typename T, template<typename, typename=std::allocator<T> > class Container>
	void mergeInsertionSort(std::vector<T> data);
	template<typename T, template<typename, typename=std::allocator<T> > class Container>
	void mergeInsertionSort(std::list<T> data);
	template<typename T, template<typename, typename=std::allocator<T> > class Container>
	void partitionAndSort(Container<PairComparisonResult<T, typename Container<T>::iterator>, \
						std::allocator<PairComparisonResult<T, typename Container<T>::iterator> > > pairs, \
						bool flag);
	template<typename T>
	void insertLosers(std::vector<PairComparisonResult<T, typename std::vector<T>::iterator> > newPairs);
	template<typename T>
	void insertLosers(std::list<PairComparisonResult<T, typename std::list<T>::iterator> > newPairs);
	template<typename T>
	static typename std::list<T>::iterator lowerBoundForList(typename std::list<T>::iterator first, typename std::list<T>::iterator last, const T& value);
	template<typename T,template<typename, typename=std::allocator<T> > class Container>
	void inputToContainer(int ac, char **av, Container<T>& dst);
};

// 定義を読み込む
#include "PmergeMe.tpp"

#endif //EXE_PMERGEME_HPP
