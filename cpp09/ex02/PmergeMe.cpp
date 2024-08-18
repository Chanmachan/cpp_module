//
// Created by chanma on 2024/04/10.
//

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
	int pow = powerOfTwo(recursive_count);
	if (data.size() / pow == 1) {
		return;
	}
	bool hasUnpairedElement = data.size() / pow % 2 != 0;
	std::cout << "recursive[" << recursive_count << "] " << "bef: ";
	printDebug(data, recursive_count);
	// ここに再帰処理する関数を作る
	for (size_t i = 0; i + pow < end; i += 2 * pow) {
		if (data[i] < data[i + pow]) {
			IteratorsGroup<std::vector<int>::iterator> lhs(data.begin() + i, data.begin() + i + pow);
			IteratorsGroup<std::vector<int>::iterator> rhs(data.begin() + i + pow, data.begin() + i + 2 * pow);
			IteratorsGroup<std::vector<int>::iterator>::swap(lhs, rhs);
		}
	}
	std::cout << "recursive[" << recursive_count << "] " << "aft: ";
	printDebug(data, recursive_count);

	mergeInsertionSort(data, end - hasUnpairedElement, recursive_count + 1);
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
	int pow = powerOfTwo(recursive_count); // このpowは、どのくらいのグループサイズで要素を分割するかを示します。
	for (size_t i = 0; i < v.size(); ++i) {
		if (i % (2 * pow) == 0) {
			std::cout << CYAN << "{" << RESET;  // 大きいグループの開始
		}
		if (i % pow == 0) {
			std::cout << BLUE << "(" << RESET;  // 小さいグループの開始
		}
		std::cout << v[i];  // 要素の値
		if ((i + 1) % pow == 0 || i == v.size() - 1) {
			std::cout << BLUE << ")" << RESET;  // 小さいグループの終了
		}
		if ((i + 1) % (2 * pow) == 0) {
			std::cout << CYAN << "}" << RESET;  // 大きいグループの終了
		}
		if (i < v.size() - 1) {
			std::cout << ", ";
		}
	}
	std::cout << std::endl;
}
