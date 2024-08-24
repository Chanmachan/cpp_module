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
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::mergeInsertionSort(std::vector<int>& data, size_t end, int recursive_count) {
#ifdef DEBUG
	//// print
	printDebug(data, recursive_count);
#endif
	typedef IteratorsGroup<std::vector<int>::iterator> IteratorsGroup;
	int pow = powerOfTwo(recursive_count);
	if (data.size() / pow == 1) {
		// 要素が2のときは比較なしで先頭にインサート
		IteratorsGroup lhs(data.begin(), data.begin() + pow / 2, true);
		IteratorsGroup rhs(data.begin() + pow / 2, data.begin() + pow, true);
		IteratorsGroup::swap(lhs, rhs);
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

	// 再帰
	mergeInsertionSort(data, end - hasUnpairedElement * pow, recursive_count + 1);

	std::vector<IteratorsGroup> it_groups;
	// insertionソートの処理
	size_t pos = 0;
	for (; pos + pow < end; pos += pow) {
		if (pos == 0) {
			// 一番先頭のLoserはWinnerの前に挿入してしまう
			IteratorsGroup lhs(data.begin(), data.begin() + pow / 2, true);
			IteratorsGroup rhs(data.begin() + pow / 2, data.begin() + pow, true);
			IteratorsGroup::swap(lhs, rhs);
			it_groups.push_back(lhs);
			it_groups.push_back(rhs);
		} else {
			it_groups.push_back(IteratorsGroup(data.begin() + pos, data.begin() + pos + pow / 2, true));
			if (pos + pow < end) { // ループの最後で2つ目のグループを追加
				it_groups.push_back(IteratorsGroup(data.begin() + pos + pow / 2, data.begin() + pos + pow, false));
			}
		}
	}
	if (data.size() / pow == 2 && data.size() % pow == 0) {
		it_groups.push_back(IteratorsGroup(data.begin() + pos, data.begin() + pos + pow / 2, true));
		it_groups.push_back(IteratorsGroup(data.begin() + pos + pow / 2, data.begin() + pos + pow, false));
	} else if (pos < data.size()) {
		it_groups.push_back(IteratorsGroup(data.begin() + pos, data.end(), false));
	}
	// Loserをバイナリリサーチで挿入していく
	// it_groupsのisIndependentの全てがtrueになるまで挿入する
	// winnersのみをみてバイナリサーチ
	std::vector<IteratorsGroup> winners;
	std::vector<IteratorsGroup> losers;
	for (std::vector<IteratorsGroup>::iterator it = it_groups.begin(); it != it_groups.end(); ++it) {
		if ((*it).getIsIndependent()) {
			winners.push_back(*it);
		}
	}
	std::vector<size_t> vec_jd = calculateJacobsthalDoubles(it_groups.size() - winners.size());
	size_t sum_js = 0;
	size_t group_id = 1;
	for (std::vector<IteratorsGroup>::iterator it = it_groups.begin(); it != it_groups.end(); ++it) {
		if (!(*it).getIsIndependent()) {
			losers.insert(losers.begin(), (*it));
		size_t jacobsthal_double = vec_jd[group_id];
		sum_js += jacobsthal_double;
		if (it_groups.size() < sum_js) {
			jacobsthal_double = it_groups.size();
		}
		if (losers.size() == jacobsthal_double) {
			for (size_t i = vec_jd[group_id]; 0 < i; --i) {
				size_t winner_count = getWinnerCount(it_groups, losers[i-1]);
				std::vector<IteratorsGroup>::iterator found_pos = binary_search(winners, winner_count, losers[i-1].getStartValue());
				losers[i-1].setIsIndependent(true);
				// ここに挿入の処理
				if (found_pos == winners.end()) {
					moveRange(data, losers[i-1].getStart(), losers[i-1].getEnd(), data.end());
				} else {
					moveRange(data, losers[i-1].getStart(), losers[i-1].getEnd(), (*found_pos).getStart());
				}
			}
			losers.clear();
			}
		}
	}
	if (!losers.empty()) {
		size_t winner_count = getWinnerCount(it_groups, losers[0]);
		std::vector<IteratorsGroup>::iterator found_pos = binary_search(winners, winner_count, losers[0].getStartValue());
		it_groups[winner_count].setIsIndependent(true);
		if (found_pos == winners.end()) {
			moveRange(data, losers[0].getStart(), losers[0].getEnd(), data.end());
		} else {
			moveRange(data, losers[0].getStart(), losers[0].getEnd(), (*found_pos).getStart());
		}
	}
#ifdef DEBUG
	//// print
	printIteratorGroups(it_groups);
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
	}
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

size_t PmergeMe::getWinnerCount(std::vector<int> v,
								std::vector<IteratorsGroup<std::vector<int>::iterator> > &winners,
								IteratorsGroup<std::vector<int>::iterator> &loser,
								size_t recursive_count) {
	typedef IteratorsGroup<std::vector<int>::iterator> IteratorsGroup;

	int pow = powerOfTwo(recursive_count);
	size_t count = 0;
	std::vector<int>::iterator it = std::find(v.begin(), v.end(), loser.getStartValue());
	it -= pow;
	for (std::vector<IteratorsGroup>::iterator it_winners = winners.begin(); it_winners != winners.end(); ++it_winners) {
		if ((*it_winners).getStartValue() == *it) {
			break;
		}
		count++;
	}
	return count;
}
