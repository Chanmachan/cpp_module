//
// Created by chanma on 2023/10/16.
//

#include "PmergeMe.hpp"
#include <iostream>

template<typename T>
typename std::list<T>::iterator PmergeMe::lowerBoundForList(typename std::list<T>::iterator first,
															typename std::list<T>::iterator last, const T &value) {
	while (first != last && *first < value) {
		first++;
	}
	return first;
}

template<typename T>
void insertLosers(std::vector<PairComparisonResult<T, typename std::vector<T>::iterator> > newPairs, std::vector<T>& ret) {
	if (newPairs.size() == 1) {
		ret.insert(ret.begin(), newPairs[0].getWinnerValue());
	}
	for (size_t i = 0; i < newPairs.size() && newPairs[i].getSize() == 2; i++) {
		typename std::vector<T>::iterator insPos = std::lower_bound(ret.begin(), ret.end(), newPairs[i].getLoserValue());
		ret.insert(insPos, newPairs[i].getLoserValue());
	}

#ifdef TEST
	for (size_t i = 0; i < ret.size(); ++i) {
		std::cout << "[" << i <<  "]" << ret[i] << std::endl;
	}
	std::cout << "-------------------------------" << std::endl;
#endif
}

template<typename T>
void insertLosers(std::list<PairComparisonResult<T, typename std::list<T>::iterator> > newPairs, std::list<T>& ret) {
	typename std::list<PairComparisonResult<T, typename std::list<T>::iterator> >::iterator it = newPairs.begin();

	if (newPairs.size() == 1) {
		ret.insert(ret.begin(), it->getWinnerValue());
	}
	for (; it != newPairs.end() && it->getSize() == 2; ++it) {
		typename std::list<T>::iterator insPos = PmergeMe::lowerBoundForList(ret.begin(), ret.end(), it->getLoserValue());
		ret.insert(insPos, it->getLoserValue());
	}

#ifdef TEST
	size_t index = 0;
    for (auto& value : ret) {
        std::cout << "[" << index++ << "]" << value << std::endl;
    }
    std::cout << "-------------------------------" << std::endl;
#endif
}


//template<typename T>
//void PartitionAndSort(std::vector<PairComparisonResult<T, typename std::vector<T>::iterator> > pairs, std::vector<T>& ret) {
//
//	if (pairs.size() <= 1) {
//		return;
//	}
//	bool hasUnpairedElement = (pairs.size() % 2) != 0;
//	std::vector<PairComparisonResult<T, typename std::vector<T>::iterator> > nextPairs;
//	typename std::vector<PairComparisonResult<T, typename std::vector<T>::iterator> >::iterator it = pairs.begin();
//	// 最後(奇数個の場合は最後の手前)までペアを作って比較してpair(勝者と敗者)に分ける
//	for (; it < pairs.end() && std::next(it) != pairs.end(); it += 2) {
//		if (it->getWinnerValue() < std::next(it)->getWinnerValue()) {
//			T tmp = it->getWinnerValue();
//			it->setWinnerValue(std::next(it)->getWinnerValue());
//			std::next(it)->setWinnerValue(tmp);
//		}
//		// ここのコンストラクタで比較してインプットする処理にしてもいいかも
//		PairComparisonResult<T, typename std::vector<T>::iterator> pair(it->getWinnerItr(), std::next(it)->getWinnerItr());
//		nextPairs.push_back(pair);
//	}
//	if (hasUnpairedElement) {
//		// 最後のあまりをpairsにいれる処理
//		PairComparisonResult<T, typename std::vector<T>::iterator> pair(it->getWinnerItr());
//		nextPairs.push_back(pair);
//	}
//	PartitionAndSort(nextPairs, ret);
//#ifdef TEST
//	std::cout << "<oldPairs> " << std::endl << "winner: ";
//	for (size_t i = 0; i < pairs.size(); ++i) {
//		std::cout << pairs[i].getWinnerValue() << ", ";
//	}
//	std::cout << std::endl << " loser: ";
//	for (size_t i = 0; i < pairs.size() && pairs[i].getSize() == 2; ++i) {
//		std::cout << pairs[i].getLoserValue() << ", ";
//	}
//	std::cout << std::endl;
//	std::cout << "<nextPairs> " << std::endl << "winner: ";
//	for (size_t i = 0; i < nextPairs.size(); ++i) {
//		std::cout << nextPairs[i].getWinnerValue() << ", ";
//	}
//	std::cout << std::endl << " loser: ";
//	for (size_t i = 0; i < nextPairs.size() && nextPairs[i].getSize() ==2; ++i) {
//		std::cout << nextPairs[i].getLoserValue() << ", ";
//	}
//	std::cout << std::endl << "------------------------------------------" << std::endl;
//#endif
//
//	// 敗者を挿入していく
//	// binary_researchを使う(lower_bound?)
//	// 元のpairsに挿入していく感じ？
//	// nextPairsのloserがpairsのwinnerにinsertする
//	// vecのendから挿入していった方が効率がいい？
//	InsertLosers(nextPairs, ret);
//}

/* テンプレートテンプレートパラメータを使うことでコンテナをtemplateにできる
 * vectorやlistは第二引数でアロケータが必要
 * defaultではT型のアロケータをセットしている
 * PairComparisonResultの集合体をコンテナとして持つ場合は、アロケータをその型でセットしなければならない
 * partitionAndSort(pairs, &ret)の形
 * */
template<typename T, template<typename, typename=std::allocator<T> > class Container>
void partitionAndSort(Container<PairComparisonResult<T, typename Container<T>::iterator>, \
						std::allocator<PairComparisonResult<T, typename Container<T>::iterator> > > pairs, \
						Container<T>& ret, bool flag) {
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
//	for (; it != pairs.end() && std::next(it) != pairs.end(); it += 2) {
//		if (it->getWinnerValue() < std::next(it)->getWinnerValue()) {
//			T tmp = it->getWinnerValue();
//			it->setWinnerValue(std::next(it)->getWinnerValue());
//			std::next(it)->setWinnerValue(tmp);
//		}
//		// ここのコンストラクタで比較してインプットする処理にしてもいいかも
//		ComparisonPair pair(it->getWinnerItr(), std::next(it)->getWinnerItr());
//		nextPairs.push_back(pair);
//	}
	if (hasUnpairedElement) {
		// 最後のあまりをpairsにいれる処理
		ComparisonPair pair(it->getWinnerItr());
		nextPairs.push_back(pair);
	}
	partitionAndSort<T, Container>(nextPairs, ret, flag);
#ifdef TEST
	std::cout << "<oldPairs> " << std::endl << "winner: ";
	for (size_t i = 0; i < pairs.size(); ++i) {
		std::cout << pairs[i].getWinnerValue() << ", ";
	}
	std::cout << std::endl << " loser: ";
	for (size_t i = 0; i < pairs.size() && pairs[i].getSize() == 2; ++i) {
		std::cout << pairs[i].getLoserValue() << ", ";
	}
	std::cout << std::endl;
	std::cout << "<nextPairs> " << std::endl << "winner: ";
	for (size_t i = 0; i < nextPairs.size(); ++i) {
		std::cout << nextPairs[i].getWinnerValue() << ", ";
	}
	std::cout << std::endl << " loser: ";
	for (size_t i = 0; i < nextPairs.size() && nextPairs[i].getSize() ==2; ++i) {
		std::cout << nextPairs[i].getLoserValue() << ", ";
	}
	std::cout << std::endl << "------------------------------------------" << std::endl;
#endif

	// 敗者を挿入していく
	// binary_researchを使う(lower_bound?)
	// 元のpairsに挿入していく感じ？
	// nextPairsのloserがソートされたpairsのwinner(->ret)にinsertされる感じ
	// vecのendから挿入していった方が効率がいい？
	if (flag) {
		insertLosers(nextPairs, ret);
	} else {
		insertLosers(nextPairs, ret);
	}
}

// mainで指定したアロケータの型に設定
template<typename T, template<typename, typename=std::allocator<T> > class Container>
std::vector<T> PmergeMe::mergeInsertionSort(std::vector<T> data) {
	// 一番最初のループなのでペアは作らずにそれぞれを一つのペアとして扱う
	std::vector<PairComparisonResult<T, typename std::vector<T>::iterator> > firstPairs;
	for (typename std::vector<T>::iterator it = data.begin(); it < data.end(); it++) {
		PairComparisonResult<T, typename std::vector<T>::iterator> pair(it);
		firstPairs.push_back(pair);
	}
	// 一旦retに返すようにする
	std::vector<T> ret;
	partitionAndSort<T, Container>(firstPairs, ret, true);

	return ret;
}

template<typename T, template<typename, typename=std::allocator<T> > class Container>
std::list<T> PmergeMe::mergeInsertionSort(std::list<T> data) {
	std::list<PairComparisonResult<T, typename std::list<T>::iterator> > firstPairs;
	for (typename std::list<T>::iterator it = data.begin(); it != data.end(); it++) {
		PairComparisonResult<T, typename std::list<T>::iterator> pair(it);
		firstPairs.push_back(pair);
	}
	std::list<T> ret;
	partitionAndSort<T, Container>(firstPairs, ret, false);

	return ret;
}
