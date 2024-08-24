//
// Created by chanma on 2024/04/10.
//

#include <iomanip>
#include <algorithm>
#include "PmergeMe.hpp"
#include "utils.hpp"
#include "IteratorsGroup.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) {
	*this = src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &src) {
	if (this != &src) {
		vec_ = src.vec_;
		deq_ = src.deq_;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}


/**********************************************/
/*                  vector                    */
/**********************************************/


void PmergeMe::mergeInsertionSort(std::vector<int>& data, size_t end, int recursive_count) {
#ifdef DEBUG
	//// print
	if (recursive_count == 0) {
		std::cout << "<making pair step>" << std::endl;
	}
	std::cout << "Before: ";
	printDebug(data, recursive_count, end);
	// printVecRecursive(data, end, recursive_count);
#endif
	typedef IteratorsGroup<std::vector<int>::iterator> IteratorsGroup;
	int pow = powerOfTwo(recursive_count);
	if (data.size() / pow == 1) {
#ifdef DEBUG
		//// print
		std::cout << "<insertion step>" << std::endl;
#endif
		return;
	}
	bool hasUnpairedElement = data.size() / pow % 2 != 0;
	// ここに再帰処理する関数を作る
	for (size_t i = 0; i + pow < end; i += 2 * pow) {
		if (data[i] < data[i + pow]) {
			IteratorsGroup lhs(data.begin() + i, data.begin() + i + pow, true);
			IteratorsGroup rhs(data.begin() + i + pow, data.begin() + i + 2 * pow, true);
			IteratorsGroup::swap(lhs, rhs);
		}
	}
#ifdef DEBUG
	//// print
		std::cout << "After:  ";
		printDebug(data, recursive_count, end);
#endif
	// 再帰
	mergeInsertionSort(data, end - hasUnpairedElement * pow, recursive_count + 1);

#ifdef DEBUG
	//// print
	std::cout << "Before: ";
	printDebug(data, recursive_count, end);
#endif
	std::vector<IteratorsGroup> it_groups;
	// insertionソートの処理
	size_t pos = 0;
	size_t quotient = end / pow;
	for (size_t i = 1; i < quotient; ++i) {
		if (i == 1) {
			// 一番先頭のLoserはWinnerの前に挿入してしまう
			IteratorsGroup lhs(data.begin(), data.begin() + pow, true);
			IteratorsGroup rhs(data.begin() + pow, data.begin() + pow * 2, true);
			IteratorsGroup::swap(lhs, rhs);
			it_groups.push_back(lhs);
			it_groups.push_back(rhs);
			if (data.size() / pow == 2) {
#ifdef DEBUG
				//// print
				std::cout << "After:  ";
				printDebug(data, recursive_count, end);
#endif
				return;
			}
		} else {
			// 偶奇でwinnerかloserかを判定
			bool isIndependent = (i % 2 == 0);
			pos = i * pow;
			it_groups.push_back(IteratorsGroup(data.begin() + pos, data.begin() + pos + pow, isIndependent));
		}
	}
	if (hasUnpairedElement) {
		it_groups[quotient-1].setIsIndependent(false);
	}

	// Loserをバイナリリサーチで挿入していく
	// it_groupsのisIndependentの全てがtrueになるまで挿入する
	// winnersのみをみてバイナリサーチ
	std::vector<IteratorsGroup> winners;
	std::vector<IteratorsGroup> losers;
	for (std::vector<IteratorsGroup>::iterator it = it_groups.begin(); it != it_groups.end(); ++it) {
		if ((*it).getIsIndependent()) {
			winners.push_back(*it);
		} else {
			losers.push_back(*it);
		}
	}

	std::vector<size_t> vec_jd = calculateJacobsthalDoubles<std::vector<size_t> >(losers.size());
	for (size_t i = 1; i < vec_jd.size(); ++i) {
		size_t j = vec_jd[i];
		if (i + 1 >= vec_jd.size()) {
			j = losers.size();
		}
		for (; 0 < j; j--) {
			size_t winner_count = getWinnerCount(data, end, winners, losers[j - 1], recursive_count);
			std::vector<IteratorsGroup>::iterator found_pos = binary_search(winners, winner_count, losers[j-1].getStartValue());
			losers[j-1].setIsIndependent(true);
			winners.insert(found_pos, losers[j-1]);
			losers.erase(losers.begin() + j-1);
		}
	}
	Copy(winners, data);
#ifdef DEBUG
	//// print
	std::cout << "After:  ";
	printDebug(data, recursive_count, end);
#endif
}

std::vector<IteratorsGroup<std::vector<int>::iterator> >::iterator
PmergeMe::binary_search(std::vector<IteratorsGroup<std::vector<int>::iterator> > &groups,
						size_t count,
						int target) {
	typedef IteratorsGroup<std::vector<int>::iterator> IteratorsGroup;

	std::vector<IteratorsGroup>::iterator first = groups.begin();
	std::vector<IteratorsGroup>::iterator mid;
	std::vector<IteratorsGroup>::iterator end;
	size_t dist = std::distance(groups.begin(), groups.begin() + count);

	for (; dist != 0; ) {
		mid = first;
		size_t half_dist = dist / 2;
		std::advance(mid, half_dist);
		if ((*mid).getStartValue() < target) {
			first = ++mid;
			dist -= half_dist + 1;
		} else {
			dist = half_dist;
		}
	}
	return first;
}

void PmergeMe::Copy(const std::vector<IteratorsGroup<std::vector<int>::iterator> > &src, std::vector<int> &dst) {
	std::vector<int> insert_data;
	for (std::vector<IteratorsGroup<std::vector<int>::iterator> >::const_iterator it = src.begin(); it != src.end(); ++it) {
		insert_data.insert(insert_data.end(), it->getStart(), it->getEnd());
	}
	std::copy(insert_data.begin(), insert_data.end(), dst.begin());
}

void PmergeMe::moveRange(std::vector<int>& data,
						 std::vector<int>::iterator start,
						 std::vector<int>::iterator end,
						 std::vector<int>::iterator new_pos) {

	if (start == new_pos) {
		return;
	}

	std::vector<int> copied(start, end);

	data.erase(start, end);

	// new_posが削除により移動した場合の調整
	if (start < new_pos && new_pos != data.end()) {
		new_pos -= distance(start, end);
	}

	data.insert(new_pos, copied.begin(), copied.end());
}

size_t PmergeMe::getWinnerCount(std::vector<int> v, size_t end,
								std::vector<IteratorsGroup<std::vector<int>::iterator> > &winners,
								IteratorsGroup<std::vector<int>::iterator> &loser, size_t recursive_count) {
	typedef IteratorsGroup<std::vector<int>::iterator> IteratorsGroup;

	int pow = powerOfTwo(recursive_count);
	size_t count = 0;
	size_t quotient = end / pow;
	std::vector<int>::iterator it = std::find(v.begin(), v.end(), loser.getStartValue());
	// あまりが存在するとき、挿入場所の探索は全体から  {1, 2}, {3, 4}, 5 <-5の探索はそれ以前の数列の全体
	if (quotient % 2 != 0) {
		if (it + pow >= v.begin() + end){
			return winners.size();
		}
	}
	it -= pow;
	std::vector<IteratorsGroup>::iterator it_winners;
	for (it_winners = winners.begin(); it_winners != winners.end(); ++it_winners) {
		count++;
		if ((*it_winners).getStartValue() == *it) {
			break;
		}
	}
	return count;
}

std::vector<int> PmergeMe::getVec() { return vec_; }

#define RESET "\033[0m"
#define BLUE "\033[34m"
#define CYAN "\033[96m"

void PmergeMe::printVec(std::vector<int> v) {
	for (size_t i = 0; i < v.size(); i++) {
		std::cout << v[i] << ", ";
	}
	std::cout << std::endl;
}

void PmergeMe::printVecRecursive(std::vector<int> v, size_t end, int recursive_count) {
	int pow = powerOfTwo(recursive_count);
	for (size_t i = 0; i + pow < end; i += 2 * pow) {
		std::cout << v[i] << ", ";
		std::cout << v[i + pow] << ", ";
		if (i + 2 * pow + pow > end) {
			if (i + 2 * pow < end) {
				std::cout << v[i + 2 * pow];
			}
		}
	}
	std::cout << "=== " << end << std::endl;

	std::cout << std::endl;
}

void PmergeMe::printDebug(std::vector<int> v, int recursive_count, size_t end) {
	int pow = powerOfTwo(recursive_count);
	size_t i = 0;
	for (; i < end; ++i) {
		if (i % (2 * pow) == 0) {
			std::cout << CYAN << "{" << RESET;
		}
		if (i % pow == 0) {
			std::cout << BLUE << "(" << RESET;
		}
		std::cout << v[i];  // 要素の値
		if ((i + 1) % pow == 0 || i == v.size() - 1) {
			std::cout << BLUE << ")" << RESET;
		}
		if ((i + 1) % (2 * pow) == 0) {
			std::cout << CYAN << "}" << RESET;
		}
		if (i < v.size() - 1) {
			std::cout << ", ";
		}
	}
	if (i != v.size()) {
		std::cout << "   left: ";
		for (; i < v.size(); ++i) {
			std::cout << v[i] << ", ";
		}
	}
	std::cout << std::endl;
}

void PmergeMe::printVecLimited(std::vector<int> v, size_t start, size_t end) {
	std::cout << "== printVecLimited" << std::endl;
	for (size_t i = start; i < end; ++i) {
		std::cout << v[i] << ", ";
	}
	std::cout << std::endl;
}

void PmergeMe::printIteratorGroups(const std::vector<IteratorsGroup<std::vector<int>::iterator> >& it_groups) {
	std::cout << "Printing Iterator Groups:" << std::endl;
	int group_number = 0;
	std::vector<IteratorsGroup<std::vector<int>::iterator> >::const_iterator group_it;
	for (group_it = it_groups.begin(); group_it != it_groups.end(); ++group_it) {
		std::cout << "Group " << group_number++ << ": ";
		std::vector<int>::const_iterator element_it;
		for (element_it = group_it->getStart(); element_it != group_it->getEnd(); ++element_it) {
			std::cout << std::setw(3) << *element_it << " ";
		}
		std::cout<< "  isIndependent-> " << std::boolalpha << group_it->getIsIndependent();
		std::cout << std::endl;
	}
}


/**********************************************/
/*                  deque                     */
/**********************************************/


void PmergeMe::mergeInsertionSort(std::deque<int>& data, size_t end, int recursive_count) {
#ifdef DEBUG
	//// print
	if (recursive_count == 0) {
		std::cout << "<making pair step>" << std::endl;
	}
	std::cout << "Before: ";
	printDebug(data, recursive_count, end);
	// printVecRecursive(data, end, recursive_count);
#endif
	typedef IteratorsGroup<std::deque<int>::iterator> IteratorsGroup;
	int pow = powerOfTwo(recursive_count);
	if (data.size() / pow == 1) {
#ifdef DEBUG
		//// print
		std::cout << "<insertion step>" << std::endl;
#endif
		return;
	}
	bool hasUnpairedElement = data.size() / pow % 2 != 0;
	// ここに再帰処理する関数を作る
	for (size_t i = 0; i + pow < end; i += 2 * pow) {
		if (data[i] < data[i + pow]) {
			IteratorsGroup lhs(data.begin() + i, data.begin() + i + pow, true);
			IteratorsGroup rhs(data.begin() + i + pow, data.begin() + i + 2 * pow, true);
			IteratorsGroup::swap(lhs, rhs);
		}
	}
#ifdef DEBUG
	//// print
		std::cout << "After:  ";
		printDebug(data, recursive_count, end);
#endif
	// 再帰
	mergeInsertionSort(data, end - hasUnpairedElement * pow, recursive_count + 1);

#ifdef DEBUG
	//// print
	std::cout << "Before: ";
	printDebug(data, recursive_count, end);
#endif
	std::deque<IteratorsGroup> it_groups;
	// insertionソートの処理
	size_t pos = 0;
	size_t quotient = end / pow;
	for (size_t i = 1; i < quotient; ++i) {
		if (i == 1) {
			// 一番先頭のLoserはWinnerの前に挿入してしまう
			IteratorsGroup lhs(data.begin(), data.begin() + pow, true);
			IteratorsGroup rhs(data.begin() + pow, data.begin() + pow * 2, true);
			IteratorsGroup::swap(lhs, rhs);
			it_groups.push_back(lhs);
			it_groups.push_back(rhs);
			if (data.size() / pow == 2) {
#ifdef DEBUG
				//// print
				std::cout << "After:  ";
				printDebug(data, recursive_count, end);
#endif
				return;
			}
		} else {
			// 偶奇でwinnerかloserかを判定
			bool isIndependent = (i % 2 == 0);
			pos = i * pow;
			it_groups.push_back(IteratorsGroup(data.begin() + pos, data.begin() + pos + pow, isIndependent));
		}
	}
	if (hasUnpairedElement) {
		it_groups[quotient-1].setIsIndependent(false);
	}

	// Loserをバイナリリサーチで挿入していく
	// it_groupsのisIndependentの全てがtrueになるまで挿入する
	// winnersのみをみてバイナリサーチ
	std::deque<IteratorsGroup> winners;
	std::deque<IteratorsGroup> losers;
	for (std::deque<IteratorsGroup>::iterator it = it_groups.begin(); it != it_groups.end(); ++it) {
		if ((*it).getIsIndependent()) {
			winners.push_back(*it);
		} else {
			losers.push_back(*it);
		}
	}

	std::deque<size_t> vec_jd = calculateJacobsthalDoubles<std::deque<size_t> >(losers.size());
	for (size_t i = 1; i < vec_jd.size(); ++i) {
		size_t j = vec_jd[i];
		if (i + 1 >= vec_jd.size()) {
			j = losers.size();
		}
		for (; 0 < j; j--) {
			size_t winner_count = getWinnerCount(data, end, winners, losers[j - 1], recursive_count);
			std::deque<IteratorsGroup>::iterator found_pos = binary_search(winners, winner_count, losers[j-1].getStartValue());
			losers[j-1].setIsIndependent(true);
			winners.insert(found_pos, losers[j-1]);
			losers.erase(losers.begin() + j-1);
		}
	}
	Copy(winners, data);
#ifdef DEBUG
	//// print
	std::cout << "After:  ";
	printDebug(data, recursive_count, end);
#endif
}

std::deque<IteratorsGroup<std::deque<int>::iterator> >::iterator
PmergeMe::binary_search(std::deque<IteratorsGroup<std::deque<int>::iterator> > &groups,
						size_t count,
						int target) {
	typedef IteratorsGroup<std::deque<int>::iterator> IteratorsGroup;

	std::deque<IteratorsGroup>::iterator first = groups.begin();
	std::deque<IteratorsGroup>::iterator mid;
	std::deque<IteratorsGroup>::iterator end;
	size_t dist = std::distance(groups.begin(), groups.begin() + count);

	for (; dist != 0; ) {
		mid = first;
		size_t half_dist = dist / 2;
		std::advance(mid, half_dist);
		if ((*mid).getStartValue() < target) {
			first = ++mid;
			dist -= half_dist + 1;
		} else {
			dist = half_dist;
		}
	}
	return first;
}

void PmergeMe::Copy(const std::deque<IteratorsGroup<std::deque<int>::iterator> > &src, std::deque<int> &dst) {
	std::deque<int> insert_data;
	for (std::deque<IteratorsGroup<std::deque<int>::iterator> >::const_iterator it = src.begin(); it != src.end(); ++it) {
		insert_data.insert(insert_data.end(), it->getStart(), it->getEnd());
	}
	std::copy(insert_data.begin(), insert_data.end(), dst.begin());
}

void PmergeMe::moveRange(std::deque<int>& data,
						 std::deque<int>::iterator start,
						 std::deque<int>::iterator end,
						 std::deque<int>::iterator new_pos) {

	if (start == new_pos) {
		return;
	}

	std::deque<int> copied(start, end);

	data.erase(start, end);

	// new_posが削除により移動した場合の調整
	if (start < new_pos && new_pos != data.end()) {
		new_pos -= distance(start, end);
	}

	data.insert(new_pos, copied.begin(), copied.end());
}

size_t PmergeMe::getWinnerCount(std::deque<int> v, size_t end,
								std::deque<IteratorsGroup<std::deque<int>::iterator> > &winners,
								IteratorsGroup<std::deque<int>::iterator> &loser, size_t recursive_count) {
	typedef IteratorsGroup<std::deque<int>::iterator> IteratorsGroup;

	int pow = powerOfTwo(recursive_count);
	size_t count = 0;
	size_t quotient = end / pow;
	std::deque<int>::iterator it = std::find(v.begin(), v.end(), loser.getStartValue());
	// あまりが存在するとき、挿入場所の探索は全体から  {1, 2}, {3, 4}, 5 <-5の探索はそれ以前の数列の全体
	if (quotient % 2 != 0) {
		if (it + pow >= v.begin() + end){
			return winners.size();
		}
	}
	it -= pow;
	std::deque<IteratorsGroup>::iterator it_winners;
	for (it_winners = winners.begin(); it_winners != winners.end(); ++it_winners) {
		count++;
		if ((*it_winners).getStartValue() == *it) {
			break;
		}
	}
	return count;
}

std::deque<int> PmergeMe::getDeq() { return deq_; }

void PmergeMe::printVec(std::deque<int> v) {
	for (size_t i = 0; i < v.size(); i++) {
		std::cout << v[i] << ", ";
	}
	std::cout << std::endl;
}

void PmergeMe::printVecRecursive(std::deque<int> v, size_t end, int recursive_count) {
	int pow = powerOfTwo(recursive_count);
	for (size_t i = 0; i + pow < end; i += 2 * pow) {
		std::cout << v[i] << ", ";
		std::cout << v[i + pow] << ", ";
		if (i + 2 * pow + pow > end) {
			if (i + 2 * pow < end) {
				std::cout << v[i + 2 * pow];
			}
		}
	}
	std::cout << "=== " << end << std::endl;

	std::cout << std::endl;
}

void PmergeMe::printDebug(std::deque<int> v, int recursive_count, size_t end) {
	int pow = powerOfTwo(recursive_count);
	size_t i = 0;
	for (; i < end; ++i) {
		if (i % (2 * pow) == 0) {
			std::cout << CYAN << "{" << RESET;
		}
		if (i % pow == 0) {
			std::cout << BLUE << "(" << RESET;
		}
		std::cout << v[i];  // 要素の値
		if ((i + 1) % pow == 0 || i == v.size() - 1) {
			std::cout << BLUE << ")" << RESET;
		}
		if ((i + 1) % (2 * pow) == 0) {
			std::cout << CYAN << "}" << RESET;
		}
		if (i < v.size() - 1) {
			std::cout << ", ";
		}
	}
	if (i != v.size()) {
		std::cout << "   left: ";
		for (; i < v.size(); ++i) {
			std::cout << v[i] << ", ";
		}
	}
	std::cout << std::endl;
}

void PmergeMe::printVecLimited(std::deque<int> v, size_t start, size_t end) {
	std::cout << "== printVecLimited" << std::endl;
	for (size_t i = start; i < end; ++i) {
		std::cout << v[i] << ", ";
	}
	std::cout << std::endl;
}

void PmergeMe::printIteratorGroups(const std::deque<IteratorsGroup<std::deque<int>::iterator> >& it_groups) {
	std::cout << "Printing Iterator Groups:" << std::endl;
	int group_number = 0;
	std::deque<IteratorsGroup<std::deque<int>::iterator> >::const_iterator group_it;
	for (group_it = it_groups.begin(); group_it != it_groups.end(); ++group_it) {
		std::cout << "Group " << group_number++ << ": ";
		std::deque<int>::const_iterator element_it;
		for (element_it = group_it->getStart(); element_it != group_it->getEnd(); ++element_it) {
			std::cout << std::setw(3) << *element_it << " ";
		}
		std::cout<< "  isIndependent-> " << std::boolalpha << group_it->getIsIndependent();
		std::cout << std::endl;
	}
}
