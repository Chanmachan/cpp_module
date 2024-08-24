//
// Created by chanma on 2024/08/17.
//

#ifndef EXE_UTILS_HPP
#define EXE_UTILS_HPP

#include <vector>
#include <deque>

int powerOfTwo(int exponent);
template<typename Container>
Container calculateJacobsthalDoubles(size_t max_sum);
template<typename Container>
Container inputToContainer(int ac, char **av);

#include "utils.tpp"

#endif //EXE_UTILS_HPP
