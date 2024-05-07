#include <iostream>
#include <sstream>
#include <fstream>
#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: number of arguments" << std::endl;
		return 1;
	}
	try {
		BitcoinExchange btcExchanger;

		btcExchanger.processInputFile(av[1]);
	} catch (const std::runtime_error& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
