//
// Created by 本間優之介 on 2022/12/13.
//

#include "Harl.hpp"

int main(){
	Harl	harl;

	std::cout << "\x1b[32m" << "[DEBUG]" << "\x1b[0m" << std::endl;
	harl.complain("DEBUG");
	std::cout << "\x1b[33m" << "[INFO]" << "\x1b[0m" << std::endl;
	harl.complain("INFO");
	std::cout << "\x1b[34m" << "[WARNING]" << "\x1b[0m" << std::endl;
	harl.complain("WARNING");
	std::cout << "\x1b[35m" << "[ERROR]" << "\x1b[0m" << std::endl;
	harl.complain("ERROR");
	std::cout << "\x1b[36m" << "[٩( ᐛ )و]" << "\x1b[0m" << std::endl;
	harl.complain("٩( ᐛ )و");
}