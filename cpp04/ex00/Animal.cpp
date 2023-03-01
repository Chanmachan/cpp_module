//
// Created by 本間優之介 on 2023/02/18.
//

#include "Animal.h"

Animal::Animal(): type("no type") {
	std::cout << "Animal " << type << " Constructor called" << std::endl;
}

Animal::Animal(const std::string& type): type(type) {
	std::cout << "Animal " << type << " set" << std::endl;
}

Animal::Animal(const Animal &src) {
	std::cout << "Animal " << type << " Copy Constructor called"<< std::endl;
	this->type = src.type;
}

Animal::~Animal() {
	std::cout << "Animal " << type << " Destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &src) {
	std::cout << "Animal " << this->type << " operator= called" << std::endl;
	if (this != &src) {
		this->type = src.type;
	}
	return *this;
}

std::string Animal::getType() const {
	return type;
}

void Animal::makeSound() const {
	std::cout << "Who am I ??" << std::endl;
}