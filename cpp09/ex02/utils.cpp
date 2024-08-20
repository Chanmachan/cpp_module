//
// Created by chanma on 2024/08/17.
//

#include "utils.hpp"

int powerOfTwo(int exponent) {
	return 1 << exponent;
}

std::vector<size_t> calculateJacobsthalDoubles(size_t max_sum) {
	std::vector<size_t> ret;
	size_t sum = 0;
	size_t j0 = 0, j1 = 1;

	ret.push_back(2 * j0);
	sum += 2 * j0;
	if (sum > max_sum) return ret;

	ret.push_back(2 * j1);
	sum += 2 * j1;
	if (sum > max_sum) return ret;

	size_t next_jacobsthal;
	while (sum <= max_sum) {
		next_jacobsthal = j1 + 2 * j0;
		j0 = j1;
		j1 = next_jacobsthal;
		size_t doubled_value = 2 * next_jacobsthal;
		sum += doubled_value;
		ret.push_back(doubled_value);
		if (sum > max_sum) break;
	}

	return ret;
}
