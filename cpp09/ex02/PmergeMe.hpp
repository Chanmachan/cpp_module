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
#include <list>
#include <iostream>

class PmergeMe {
private:
	std::vector<int> vec_;
public:
	PmergeMe();
	PmergeMe(const PmergeMe& src);
	PmergeMe& operator=(const PmergeMe& src);
	~PmergeMe();

	void inputToContainer(int ac, char **av, std::vector<int>& dst);
	void mergeInsertionSort(std::vector<int> data);

	std::vector<int> getVec();
};

inline std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec) {
	for (size_t i = 0; i < vec.size(); ++i) {
		os << vec[i] << " ";
	}
	return os;
}

//template<typename int>
//std::ostream& operator<<(std::ostream& os, const std::list<int>& lst) {
//	for (typename std::list<T>::const_iterator it = lst.begin(); it != lst.end(); it++) {
//		os << *it << " ";
//	}
//	return os;
//}

#endif //EXE_PMERGEME_HPP
