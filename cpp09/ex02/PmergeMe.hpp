//
// Created by chanma on 2023/10/16.
//

#ifndef EXE_PMERGEME_HPP
#define EXE_PMERGEME_HPP

#include <vector>
#include <list>

class PmergeMe {
private:

public:
	std::vector<int> inputVec(int ac, const char **av);
	template<typename T>
	static void mergeInsertionSort(std::vector<T> data);
	template<typename T>
	static void mergeInsertionSort(std::list<T> data);
};


#endif //EXE_PMERGEME_HPP
