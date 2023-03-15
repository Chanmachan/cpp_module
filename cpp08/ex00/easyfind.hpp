//
// Created by 本間優之介 on 2023/03/14.
//

#ifndef EXE_EASYFIND_HPP
#define EXE_EASYFIND_HPP

#include <algorithm>

template<typename T>
typename T::iterator easyfind(T& arr, int target) {
	typename T::iterator itr = std::find(arr.begin(), arr.end(), target);
	if (itr == arr.end()) {
		throw std::runtime_error("Not found");
	}
	return itr;
}

// constのiteratorを返す
template<typename T>
typename T::const_iterator easyfind(const T& arr, int target) {
	typename T::const_iterator itr = std::find(arr.begin(), arr.end(), target);
	if (itr == arr.end()) {
		throw std::runtime_error("Not found");
	}
	return itr;
}

#endif //EXE_EASYFIND_HPP
