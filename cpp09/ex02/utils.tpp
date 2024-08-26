#include "utils.hpp"
#include <cstring>
#include <cstdlib>
#include <cerrno>
#include <algorithm>

template<typename Container>
Container calculateJacobsthalDoubles(size_t max_sum) {
	Container ret;
	size_t sum = 0;
	size_t j0 = 0, j1 = 1;

	ret.push_back(2 * j0);
	sum += 2 * j0;
	if (sum >= max_sum) return ret;

	ret.push_back(2 * j1);
	sum += 2 * j1;
	if (sum >= max_sum) return ret;

	size_t next_jacobsthal;
	while (sum <= max_sum) {
		next_jacobsthal = j1 + 2 * j0;
		j0 = j1;
		j1 = next_jacobsthal;
		size_t doubled_value = 2 * next_jacobsthal;
		sum += doubled_value;
		ret.push_back(doubled_value);
		if (sum >= max_sum) break;
	}

	return ret;
}

template<typename Container>
Container inputToContainer(int ac, char **av) {
	Container dst;
	if (ac > 42000) {
		throw std::invalid_argument("too many args: max 42000");
	}
	for (int i = 1; i < ac; i++) {
		errno = 0;
		char *p_end;
		long l = std::strtol(av[i], &p_end, 10);
		if (*p_end != '\0' || errno == ERANGE || errno == EINVAL || \
			strlen(av[i]) > 11 || l < 0 || l > 2147483647) {
			throw std::invalid_argument("Invalid Arg");
		}
		int value = (int)l;
		if (std::find(dst.begin(), dst.end(), value) != dst.end()) {
			throw std::invalid_argument("Duplicate value detected");
		}
		dst.push_back((int)l);
	}
	if (std::is_sorted(dst.begin(), dst.end())) {
		throw std::invalid_argument("Arguments are already sorted");
	}
	return dst;
}

template<typename Container>
bool isSorted(const Container& container) {
	typename Container::const_iterator it = container.begin();
	if (it == container.end()) return true; // 空のコンテナはソートされていると見なす

	typename Container::const_iterator prev = it;
	it++;

	while (it != container.end()) {
		if (*prev > *it) {
			return false;
		}
		prev = it;
		it++;
	}
	return true;
}
