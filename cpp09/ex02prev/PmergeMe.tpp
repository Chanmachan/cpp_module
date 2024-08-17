//
// Created by chanma on 2023/10/16.
//

/*
 * [vector]
 * 連続したメモリ上にデータを格納するためランダムアクセス(任意の要素への直接アクセス)が早い
 * キャッシュ効率がいい。メモリが一列なのでキャッシュライン(キャッシュメモリのひとまとまりの単位のようなもの)に一度に多くデータをロードできるから早い。
 * 要素の追加や削除(特に中間)には時間がかかるが、ソート中は交換の工程が多いので今回はデメリットが少ない。
 *
 * [list]
 * 双方向連結リストで、メモリ上にばらばらに存在しがちなのでランダムアクセスが遅い。要素間を移動するにはポインタをたどる必要がある。
 * リストは挿入や削除がO(1)で行えるため小規模なデータセットでは有利だが、
 * ソートでは比較と移動が多いのでポインタをたどるオーバーヘッドにより数が増えてくると遅い。
 * キャッシュ効率悪い(メモリがちらばってるから)ので、要素が多いと性能が低下しやすい。
 *
 * ※キャッシュメモリ
 * CPUのメモリ。通常のメモリよりCPUから高速なアクセスが可能だが少量。
 * ※キャッシュ効率
 * まぁキャッシュメモリにどれだけ効率よく格納・アクセスできるかみたいな
 */

#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>
#include <iomanip>

template<typename T,template<typename, typename=std::allocator<T> > class Container>
void PmergeMe::inputToContainer(int ac, char **av, Container<T>& dst) {
	if (ac > 42000) {
		throw std::invalid_argument("too many args: max 42000");
	}
	for (int i = 1; i < ac; i++) {
		errno = 0;
		char *p_end;
		long l = std::strtol(av[i], &p_end, 10);
		if (*p_end != '\0' || errno == ERANGE || errno == EINVAL || \
			strlen(av[i]) > 11 || l <= 0 || l > 2147483647) {
			throw std::invalid_argument("Invalid Arg");
		}
		int value = (int)l;
		if (std::find(dst.begin(), dst.end(), value) != dst.end()) {
			throw std::invalid_argument("Duplicate value detected");
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
template<typename T>
void PmergeMe::myDebug(std::vector<PairComparisonResult<T, typename std::vector<T>::iterator> > nextPairs) {
	std::cout << "Winner: ";
	for (size_t i = 0; i < nextPairs.size(); ++i) {
		std::cout << std::setw(2) << nextPairs[i].getWinnerValue() << ", ";
	}
	std::cout << std::endl << "Loser : ";
	for (size_t i = 0; i < nextPairs.size(); ++i) {
		std::cout << std::setw(2) << nextPairs[i].getLoserValue() << ", ";
	}
	std::cout << std::endl;
}

template<typename T>
void PmergeMe::myDebug(std::list<PairComparisonResult<T, typename std::list<T>::iterator> > nextPairs) {
	(void)nextPairs;
}

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
	for (; it != pairs.end();) {
		typename Container<ComparisonPair, std::allocator<ComparisonPair> >::iterator next_it = it;
		std::advance(next_it, 1);
		if (next_it == pairs.end()) {
			break;
		}
		if (it->getWinnerValue() < next_it->getWinnerValue()) {
			// イテレーターを入れ替えるように
			std::swap(it, next_it);
			ComparisonPair pair(it->getWinnerItr(), next_it->getWinnerItr());
			nextPairs.push_back(pair);
			std::advance(it, 1);
		} else {
			ComparisonPair pair(it->getWinnerItr(), next_it->getWinnerItr());
			nextPairs.push_back(pair);
			std::advance(it, 2);
		}
	}
	// 次の再帰に送らない
//	if (hasUnpairedElement) {
//		// 最後のあまりをpairsにいれる処理
//		ComparisonPair pair(it->getWinnerItr());
//		nextPairs.push_back(pair);
//	}
#ifdef DEBUG
	if (containerType == VECTOR) {
		myDebug(nextPairs);
	} else if (containerType == LIST){
		myDebug(nextPairs);
	}
#endif
	(void )hasUnpairedElement;
	partitionAndSort<T, Container>(nextPairs, containerType);
	// 敗者を挿入していく
	// binary_researchを使う(lower_bound?)
	// 元のpairsに挿入していく感じ？
	// nextPairsのloserがソートされたpairsのwinner(->ret)にinsertされる感じ
//	if (containerType == VECTOR) {
//		insertLosers(nextPairs);
//	} else if (containerType == LIST){
//		insertLosers(nextPairs);
//	}
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
#ifdef DEBUG_VEC
		for (size_t i = 0; i < vec_.size(); ++i) {
			std::cout << vec_[i] << " ";
		}
		std::cout << std::endl;
#endif
}

template<typename T, template<typename, typename=std::allocator<T> > class Container>
void PmergeMe::mergeInsertionSort(std::list<T> data) {
	std::list<PairComparisonResult<T, typename std::list<T>::iterator> > firstPairs;
	for (typename std::list<T>::iterator it = data.begin(); it != data.end(); it++) {
		PairComparisonResult<T, typename std::list<T>::iterator> pair(it);
		firstPairs.push_back(pair);
	}
	partitionAndSort<T, Container>(firstPairs, LIST);
#ifdef DEBUG_LST
	for (typename std::list<T>::const_iterator it = lst_.begin(); it != lst_.end(); it++) {
			std::cout << *it << " ";
	}
	std::cout << std::endl;
#endif
}
