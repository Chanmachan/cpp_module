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
	enum ContainerType {
		VECTOR,
		LIST,
	};
public:
	PmergeMe();
	PmergeMe(const PmergeMe& src);
	PmergeMe& operator=(const PmergeMe& src);
	~PmergeMe();

	template<typename T, template<typename, typename=std::allocator<T> > class Container>
	void mergeInsertionSort(std::vector<T> data);
	template<typename T, template<typename, typename=std::allocator<T> > class Container>
	void mergeInsertionSort(std::list<T> data);
	template<typename T, template<typename, typename=std::allocator<T> > class Container>
	void partitionAndSort(Container<PairComparisonResult<T, typename Container<T>::iterator>, \
						std::allocator<PairComparisonResult<T, typename Container<T>::iterator> > > pairs, \
						ContainerType containerType);
	template<typename T>
	void insertLosers(std::vector<PairComparisonResult<T, typename std::vector<T>::iterator> > newPairs);
	template<typename T>
	void insertLosers(std::list<PairComparisonResult<T, typename std::list<T>::iterator> > newPairs);
	template<typename T>
	static typename std::list<T>::iterator lowerBoundForList(typename std::list<T>::iterator first, typename std::list<T>::iterator last, const T& value);
	template<typename T,template<typename, typename=std::allocator<T> > class Container>
	void inputToContainer(int ac, char **av, Container<T>& dst);

	std::vector<int> getVec() { return vec_; };
	std::list<int> getLst() { return lst_; };

	template<typename T>
	void myDebug(std::vector<PairComparisonResult<T, typename std::vector<T>::iterator> > nextPairs);
	template<typename T>
	void myDebug(std::list<PairComparisonResult<T, typename std::list<T>::iterator> > nextPairs);
};

// 定義を読み込む
#include "PmergeMe.tpp"

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
	for (size_t i = 0; i < vec.size(); ++i) {
		os << vec[i] << " ";
	}
	return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::list<T>& lst) {
	for (typename std::list<T>::const_iterator it = lst.begin(); it != lst.end(); it++) {
		os << *it << " ";
	}
	return os;
}

#endif //EXE_PMERGEME_HPP
