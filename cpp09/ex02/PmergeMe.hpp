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

#ifndef EXE_PMERGEME_HPP
#define EXE_PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include "IteratorsGroup.hpp"

class PmergeMe {
private:
	std::vector<int> vec_;
	std::deque<int> deq_;
public:
	PmergeMe();
	PmergeMe(const PmergeMe& src);
	PmergeMe& operator=(const PmergeMe& src);
	~PmergeMe();

	/* vector */
	void mergeInsertionSort(std::vector<int>& data, size_t end, int recursive_count);
	static std::vector<IteratorsGroup<std::vector<int>::iterator> >::iterator
	binary_search(std::vector<IteratorsGroup<std::vector<int>::iterator> > &groups, size_t count, int target);
	void moveRange(std::vector<int>& data,
				   std::vector<int>::iterator start,
				   std::vector<int>::iterator end,
				   std::vector<int>::iterator new_pos);
	void Copy(const std::vector<IteratorsGroup<std::vector<int>::iterator> > &src, std::vector<int> &dst);
	size_t getWinnerCount(std::vector<int> v,
						  std::vector<IteratorsGroup<std::vector<int>::iterator> > &winners,
						  IteratorsGroup<std::vector<int>::iterator> &loser,
						  size_t recursive_count);
	std::vector<int> getVec();
	static void printVec(std::vector<int> v);
	static void printVecRecursive(std::vector<int> v, size_t end, int recursive_count);
	static void printDebug(std::vector<int> v, int recursive_count, size_t end);
	static void printVecLimited(std::vector<int> v, size_t start, size_t end);
	static void printIteratorGroups(const std::vector<IteratorsGroup<std::vector<int>::iterator> >& it_groups);

	/* deque */
	void mergeInsertionSort(std::deque<int>& data, size_t end, int recursive_count);
	static std::deque<IteratorsGroup<std::deque<int>::iterator> >::iterator
	binary_search(std::deque<IteratorsGroup<std::deque<int>::iterator> > &groups, size_t count, int target);
	void moveRange(std::deque<int>& data,
				   std::deque<int>::iterator start,
				   std::deque<int>::iterator end,
				   std::deque<int>::iterator new_pos);
	void Copy(const std::deque<IteratorsGroup<std::deque<int>::iterator> > &src, std::deque<int> &dst);
	size_t getWinnerCount(std::deque<int> v,
						  std::deque<IteratorsGroup<std::deque<int>::iterator> > &winners,
						  IteratorsGroup<std::deque<int>::iterator> &loser,
						  size_t recursive_count);
	std::deque<int> getDeq();
	static void printVec(std::deque<int> v);
	static void printVecRecursive(std::deque<int> v, size_t end, int recursive_count);
	static void printDebug(std::deque<int> v, int recursive_count, size_t end);
	static void printVecLimited(std::deque<int> v, size_t start, size_t end);
	static void printIteratorGroups(const std::deque<IteratorsGroup<std::deque<int>::iterator> >& it_groups);
};

template <typename T>
inline std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
	for (size_t i = 0; i < vec.size(); ++i) {
		os << vec[i] << " ";
	}
	return os;
}

template <typename T>
inline std::ostream& operator<<(std::ostream& os, const std::deque<T>& vec) {
	for (size_t i = 0; i < vec.size(); ++i) {
		os << vec[i] << " ";
	}
	return os;
}

#endif //EXE_PMERGEME_HPP
