//
// Created by chanma on 2024/08/17.
//

#include "utils.hpp"

int powerOfTwo(int exponent) {
	return 1 << exponent;
}

std::vector<int> calculateJacobsthalDoubles(int max_sum) {
	std::vector<int> ret;
	int sum = 0;
	int j0 = 0, j1 = 1;

	ret.push_back(2 * j0);
	sum += 2 * j0;
	if (sum > max_sum) return ret;

	ret.push_back(2 * j1);
	sum += 2 * j1;
	if (sum > max_sum) return ret;

	int next_jacobsthal;
	while (sum <= max_sum) {
		next_jacobsthal = j1 + 2 * j0;
		j0 = j1;
		j1 = next_jacobsthal;
		int doubled_value = 2 * next_jacobsthal;
		sum += doubled_value;
		ret.push_back(doubled_value);
		if (sum > max_sum) break;
	}

	return ret;
}
