//
// Created by 本間優之介 on 2023/03/11.
//

#ifndef EXE_ITER_HPP
#define EXE_ITER_HPP

#include <iostream>

template<typename T>
void iter(T* array, size_t len, void (*f)(T&)) {
	for (size_t i = 0; i < len; i++) {
		f(array[i]);
	}
}

template<typename T>
void iter(const T* array, size_t len, void (*f)(const T&)) {
	for (size_t i = 0; i < len; i++) {
		f(array[i]);
	}
}

template<typename T>
void iter(T* array, size_t len, void (*f)(T)) {
	for (size_t i = 0; i < len; i++) {
		f(array[i]);
	}
}

template<typename T>
void iter(const T* array, size_t len, void (*f)(const T)) {
	for (size_t i = 0; i < len; i++) {
		f(array[i]);
	}
}

#endif //EXE_ITER_HPP
