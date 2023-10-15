#include <iostream>
#include <sstream>
#include <fstream>
#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		return 1;
	}
	try {
		BitcoinExchange btcExchanger;
	} catch (const std::runtime_error& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	// input.txtのチェック
	(void)av;
	return 0;
}
