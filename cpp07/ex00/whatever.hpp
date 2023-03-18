//
// Created by 本間優之介 on 2023/03/11.
//

#ifndef EXE_WHATEVER_HPP
#define EXE_WHATEVER_HPP

template<typename T>
void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
const T& min(const T& a, const T& b) {
	return a >= b ? b : a;
}

template<typename T>
const T& max(const T& a, const T& b) {
	return a >= b ? a : b;
}

#endif //EXE_WHATEVER_HPP
