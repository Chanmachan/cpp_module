//
// Created by chanma on 2024/04/10.
//

#include <iomanip>
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

void PmergeMe::inputToContainer(int ac, char **av, std::vector<int>& dst) {
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

void PmergeMe::mergeInsertionSort(std::vector<int>& data, size_t end, int recursive_count) {
	typedef IteratorsGroup<std::vector<int>::iterator> IteratorsGroup;
	int pow = powerOfTwo(recursive_count);
	if (data.size() / pow == 1) {
		printDebug(data, recursive_count);
		return;
	}
	bool hasUnpairedElement = data.size() / pow % 2 != 0;
	std::cout << "recursive[" << recursive_count << "] " << "bef: ";
	printDebug(data, recursive_count);
	// ここに再帰処理する関数を作る
	for (size_t i = 0; i + pow < end; i += 2 * pow) {
		if (data[i] < data[i + pow]) {
			IteratorsGroup lhs(data.begin() + i, data.begin() + i + pow, true);
			IteratorsGroup rhs(data.begin() + i + pow, data.begin() + i + 2 * pow, true);
			IteratorsGroup::swap(lhs, rhs);
		}
	}
	std::cout << "recursive[" << recursive_count << "] " << "aft: ";
	printDebug(data, recursive_count);

	mergeInsertionSort(data, end - hasUnpairedElement, recursive_count + 1);

	std::vector<IteratorsGroup> it_groups;

	std::cout << "recursive[" << recursive_count << "] " << "bef: ";
	printDebug(data, recursive_count);
	// insertionソートの処理
	if (data.size() / pow == 2) {
		// recursive_count == 3
		printVecRecursive(data, end, recursive_count);
		// 要素が2のときは比較なしで先頭にインサート
		IteratorsGroup lhs(data.begin(), data.begin()+ pow, true);
		IteratorsGroup rhs(data.begin() + pow, data.begin() + 2 * pow, true);
		IteratorsGroup::swap(lhs, rhs);
		std::cout << "                : ";
		printDebug(data, recursive_count);
	}
	size_t i = 0;
	for (; i + pow < end; i += pow) {
		if (i == 0) {
			// 一番先頭のLoserはWinnerの前に挿入してしまう
			IteratorsGroup lhs(data.begin(), data.begin() + pow / 2, true);
			IteratorsGroup rhs(data.begin() + pow / 2, data.begin() + pow, true);
			IteratorsGroup::swap(lhs, rhs);
			it_groups.push_back(lhs);
			it_groups.push_back(rhs);
		} else {
			it_groups.push_back(IteratorsGroup(data.begin() + i, data.begin() + i + pow / 2, true));
			if (i + pow < end) { // ループの最後で2つ目のグループを追加
				it_groups.push_back(IteratorsGroup(data.begin() + i + pow / 2, data.begin() + i + 2 * pow / 2, false));
			}
		}
	}
	if (i < data.size()) {
		it_groups.push_back(IteratorsGroup(data.begin() + i, data.end(), false));
	}
	std::cout << "recursive[" << recursive_count << "] " << "aft: ";
	printDebug(data, recursive_count);
	printVecRecursive(data, end, recursive_count);
	// Loserをバイナリリサーチで挿入していく
	// it_groupsのisIndependentの全てがtrueになるまで挿入する
	// 最終的にはヤコブスタール数を使って挿入
	printIteratorGroups(it_groups);
	// winnersのみをみてバイナリサーチ
	std::vector<IteratorsGroup> winners;
	for (std::vector<IteratorsGroup>::iterator it = it_groups.begin(); it != it_groups.end(); ++it) {
		if ((*it).getIsIndependent()) {
			winners.push_back(*it);
		}
	}
	printIteratorGroups(winners);
	size_t winner_count = 0;
	for (std::vector<IteratorsGroup>::iterator it = it_groups.begin(); it != it_groups.end(); ++it) {
		if (!(*it).getIsIndependent()) {
			std::vector<IteratorsGroup>::iterator result = binary_search(winners, winner_count, (*it).getStartValue());
			if (result != winners.end()) {
				std::cout << "binary_search: to_find->" << (*it).getStartValue() << "  found->" << (*result).getStartValue() << std::endl;
			} else {
				std::cout << "binary_search: to_find->" << (*it).getStartValue() << "  found->" << "Not found" << std::endl;
			}
		} else {
			winner_count++;
		}
	}
}

std::vector<IteratorsGroup<std::vector<int>::iterator>>::iterator
PmergeMe::binary_search(std::vector<IteratorsGroup<std::vector<int>::iterator> > &it_groups,
						size_t count,
						int target) {
	typedef IteratorsGroup<std::vector<int>::iterator> IteratorsGroup;

	std::vector<IteratorsGroup>::iterator first = it_groups.begin();
	std::vector<IteratorsGroup>::iterator mid;
	std::vector<IteratorsGroup>::iterator end;
	size_t dist = std::distance(it_groups.begin(), it_groups.begin() + count);

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

std::vector<int> PmergeMe::getVec() { return vec_; }

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

const char* RESET = "\033[0m";
const char* BLUE = "\033[34m";
const char* CYAN = "\033[96m";

void PmergeMe::printDebug(std::vector<int> v, int recursive_count) {
	int pow = powerOfTwo(recursive_count);
	for (size_t i = 0; i < v.size(); ++i) {
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
	std::cout << std::endl;
}

void PmergeMe::printVecLimited(std::vector<int> v, size_t start, size_t end) {
	std::cout << "== printVecLimited" << std::endl;
	for (size_t i = start; i < end; ++i) {
		std::cout << v[i] << ", ";
	}
	std::cout << std::endl;
}

void PmergeMe::printIteratorGroups(const std::vector<IteratorsGroup<std::vector<int>::iterator>>& it_groups) {
	std::cout << "Printing Iterator Groups:" << std::endl;
	int group_number = 0;
	for (const auto& group : it_groups) {
		std::cout << "Group " << group_number++ << ": ";
		for (auto it = group.getStart(); it != group.getEnd(); ++it) {
			std::cout << std::setw(3) << *it << " ";
		}
		std::cout<< "  isIndependent-> " << std::boolalpha << group.getIsIndependent();
		std::cout << std::endl;
	}
}
