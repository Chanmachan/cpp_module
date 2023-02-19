//
// Created by 本間優之介 on 2023/02/18.
//

#include "WrongAnimal.h"

WrongAnimal::WrongAnimal(): type("no type") {
	std::cout << "WrongAnimal type not set"<< std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type): type(type) {
	std::cout << type << " set" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
	this->type = src.type;
	std::cout << "WrongAnimal " << this->type << " is duplicated"<< std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal " << this->type << " unset" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &src) {
	std::cout << "WrongAnimal " << this->type << " operator= called" << std::endl;
	this->type = src.type;
	return *this;
}

std::string WrongAnimal::getType() const {
	return type;
}

void WrongAnimal::makeSound() const {
	std::cout << "\033[31mWho am I ??\033[m" << std::endl;
}