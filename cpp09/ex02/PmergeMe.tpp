//
// Created by chanma on 2023/10/16.
//

#include "PmergeMe.hpp"
#include <iostream>

template<typename T,template<typename, typename=std::allocator<T> > class Container>
void PmergeMe::inputToContainer(int ac, char **av, Container<T>& dst) {
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

template<typename T>
typename std::list<T>::iterator PmergeMe::lowerBoundForList(typename std::list<T>::iterator first,
															typename std::list<T>::iterator last, const T &value) {
	while (first != last && *first < value) {
		first++;
	}
	return first;
}

template<typename T>
void PmergeMe::insertLosers(std::vector<PairComparisonResult<T, typename std::vector<T>::iterator> > newPairs) {
	if (newPairs.size() == 1) {
		vec_.insert(vec_.begin(), newPairs[0].getWinnerValue());
	}
	for (size_t i = 0; i < newPairs.size() && newPairs[i].getSize() == 2; i++) {
		typename std::vector<T>::iterator insPos = std::lower_bound(vec_.begin(), vec_.end(), newPairs[i].getLoserValue());
		vec_.insert(insPos, newPairs[i].getLoserValue());
	}
}

template<typename T>
void PmergeMe::insertLosers(std::list<PairComparisonResult<T, typename std::list<T>::iterator> > newPairs) {
	typename std::list<PairComparisonResult<T, typename std::list<T>::iterator> >::iterator it = newPairs.begin();

	if (newPairs.size() == 1) {
		lst_.insert(lst_.begin(), it->getWinnerValue());
	}
	for (; it != newPairs.end() && it->getSize() == 2; ++it) {
		typename std::list<T>::iterator insPos = PmergeMe::lowerBoundForList(lst_.begin(), lst_.end(), it->getLoserValue());
		lst_.insert(insPos, it->getLoserValue());
	}
}

/* テンプレートテンプレートパラメータを使うことでコンテナをtemplateにできる
 * vectorやlistは第二引数でアロケータが必要
 * defaultではT型のアロケータをセットしている
 * PairComparisonResultの集合体をコンテナとして持つ場合は、アロケータをその型でセットしなければならない
 * partitionAndSort(pairs, &ret)の形
 * */
template<typename T, template<typename, typename=std::allocator<T> > class Container>
void PmergeMe::partitionAndSort(Container<PairComparisonResult<T, typename Container<T>::iterator>, \
						std::allocator<PairComparisonResult<T, typename Container<T>::iterator> > > pairs, \
						ContainerType containerType) {
	typedef PairComparisonResult<T, typename Container<T>::iterator> ComparisonPair;
	if (pairs.size() <= 1) {
		return;
	}
	bool hasUnpairedElement = (pairs.size() % 2) != 0;
	Container<ComparisonPair, std::allocator<ComparisonPair> > nextPairs;
	typename Container<ComparisonPair, std::allocator<ComparisonPair> >::iterator it = pairs.begin();
	// 最後(奇数個の場合は最後の手前)までペアを作って比較してpair(勝者と敗者)に分ける
	// 二つずつ進める
	for (; it != pairs.end(); std::advance(it, 2)) {
		typename Container<ComparisonPair, std::allocator<ComparisonPair> >::iterator next_it = it;
		std::advance(next_it, 1);
		if (next_it == pairs.end()) {
			break;
		}
		if (it->getWinnerValue() < next_it->getWinnerValue()) {
			T tmp = it->getWinnerValue();
			it->setWinnerValue(next_it->getWinnerValue());
			next_it->setWinnerValue(tmp);
		}
		ComparisonPair pair(it->getWinnerItr(), next_it->getWinnerItr());
		nextPairs.push_back(pair);
	}
	if (hasUnpairedElement) {
		// 最後のあまりをpairsにいれる処理
		ComparisonPair pair(it->getWinnerItr());
		nextPairs.push_back(pair);
	}
	partitionAndSort<T, Container>(nextPairs, containerType);

	// 敗者を挿入していく
	// binary_researchを使う(lower_bound?)
	// 元のpairsに挿入していく感じ？
	// nextPairsのloserがソートされたpairsのwinner(->ret)にinsertされる感じ
	// vecのendから挿入していった方が効率がいい？
	if (containerType == VECTOR) {
		insertLosers(nextPairs);
	} else if (containerType == LIST){
		insertLosers(nextPairs);
	}
}

// mainで指定したアロケータの型に設定
template<typename T, template<typename, typename=std::allocator<T> > class Container>
void PmergeMe::mergeInsertionSort(std::vector<T> data) {
	// 一番最初のループなのでペアは作らずにそれぞれを一つのペアとして扱う
	std::vector<PairComparisonResult<T, typename std::vector<T>::iterator> > firstPairs;
	for (typename std::vector<T>::iterator it = data.begin(); it < data.end(); it++) {
		PairComparisonResult<T, typename std::vector<T>::iterator> pair(it);
		firstPairs.push_back(pair);
	}
	partitionAndSort<T, Container>(firstPairs, VECTOR);
}

template<typename T, template<typename, typename=std::allocator<T> > class Container>
void PmergeMe::mergeInsertionSort(std::list<T> data) {
	std::list<PairComparisonResult<T, typename std::list<T>::iterator> > firstPairs;
	for (typename std::list<T>::iterator it = data.begin(); it != data.end(); it++) {
		PairComparisonResult<T, typename std::list<T>::iterator> pair(it);
		firstPairs.push_back(pair);
	}
	partitionAndSort<T, Container>(firstPairs, LIST);
}
