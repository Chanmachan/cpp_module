//
// Created by chanma on 2023/10/16.
//

#include "PmergeMe.hpp"

std::vector<int> PmergeMe::inputVec(int ac, char **av) {
	std::vector<int> vec;
	for (int i = 0; i < ac; i++) {
		errno = 0;
		char *p_end;
		long l = std::strtol(av[i], &p_end, 10);
		if ((*p_end != '\0') || (errno == ERANGE) || (errno == EINVAL)) {
			throw std::invalid_argument("Invalid Arg");
		}
		vec.push_back((int)l);
	}
	return vec;
}

template<typename T>
void recursivePartitionAndSort(std::vector<PairComparisonResult<T, typename std::vector<T>::iterator> > pairs) {
	if (pairs.size() <= 1) {
		return;
	}
	bool hasUnpairedElement = (pairs.size() % 2) != 0;
	std::vector<PairComparisonResult<T, typename std::vector<T>::iterator> > nextPairs;
	typename std::vector<PairComparisonResult<T, typename std::vector<T>::iterator> > it = pairs.begin();
	// 最後(奇数個の場合は最後の手前)までペアを作って比較してpair(勝者と敗者)に分ける
	for (; it < pairs.end() && std::next(it) != pairs.end(); it += 2) {
		if (it->getWinnerValue() < std::next(it)->getWinnerValue()) {
			T tmp = it->getWinnerValue();
			it->setWinnerValue(std::next(it)->getWinnerValue());
			std::next(it)->setWinnerValue(tmp);
		}
		// ここのコンストラクタで比較してインプットする処理にしてもいいかも
		PairComparisonResult<T, typename std::vector<T>::iterator> pair(it, std::next(it));
		nextPairs.push_back(pair);
	}
	if (hasUnpairedElement) {
		// 最後のあまりをpairsにいれる処理
		PairComparisonResult<T, typename std::vector<T>::iterator> pair(it);
		nextPairs.push_back(pair);
	}
	recursivePartitionAndSort(nextPairs);
}

template<typename T>
void PmergeMe::mergeInsertionSort(std::vector<T> data) {
	// 一番最初のループなのでペアは作らずにそれぞれを一つのペアとして扱う
	std::vector<PairComparisonResult<T, typename std::vector<T>::iterator> > firstPairs;
	for (typename std::vector<T>::iterator it = data.begin(); it < data.end(); it++) {
		PairComparisonResult<T, typename std::vector<T>::iterator> pair(it);
		firstPairs.push_back(pair);
	}
	recursivePartitionAndSort(firstPairs);
}

template<typename T>
void PmergeMe::mergeInsertionSort(std::list<T> data) {
	(void)data;
	return;
}
