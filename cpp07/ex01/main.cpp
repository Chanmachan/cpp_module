//
// Created by 本間優之介 on 2023/03/11.
//

#include "iter.hpp"

template<typename T>
void print(const T& t) {
	std::cout << t << std::endl;
}

template<typename T>
void add(T& t) {
	t += t;
	std::cout << t << std::endl;
}

int main() {
	std::cout << "[TEST1]" << std::endl;
	int a[4] = {1, 2, 3, 4};
	iter(a, 4, add);
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "[TEST2]" << std::endl;
	int b[4] = {1, 2, 3, 4};
	iter(b, 4, print);
}
