//
// Created by 本間優之介 on 2022/12/13.
//

#include "Harl.hpp"

Harl::Harl() {

}

Harl::~Harl() {

}

void Harl::debug() {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info() {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
	std::cout <<  "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
	std::string	_levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*levels[4])(void);

	levels[0] = &Harl::debug;
	levels[1] = &Harl::info;
	levels[2] = &Harl::warning;
	levels[3] = &Harl::error;

	for (size_t i = 0; i < 4; i++){
		if (level == _levels[i]){
			(this->*levels[i])();
			return;
		}
	}
	std::cerr << "\x1b[31m" << "Error" << "\x1b[0m" << std::endl;
}
