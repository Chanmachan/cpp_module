//
// Created by chanma on 2023/10/16.
//

#include <iostream>

int main(int ac, char **av) {
	if (ac <= 1) {
		return 1;
	}
	std::cout << av[1] << std::endl;
	return 0;
}
