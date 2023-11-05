//
// Created by chanma on 2023/10/16.
//

#include <iostream>
#include "RPN.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
	try {
		RPN calculator;
		calculator.processRpn(av[1]);
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}