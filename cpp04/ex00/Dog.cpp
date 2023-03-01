//
// Created by 本間優之介 on 2023/02/18.
//

#include "Dog.h"

Dog::Dog(): Animal("Dog") {
	std::cout << "Dog " << type << " Constructor called" << std::endl;
}

Dog::Dog(const Dog &src)  : Animal(src) {
	std::cout << "Dog " << type << " Copy Constructor called"<< std::endl;
}

Dog::~Dog() {
	std::cout << "Dog " << type << " Destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &src) {
	std::cout << "Dog " << this->type << " operator= called" << std::endl;
	if (this != &src) {
		this->type = src.type;
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Bow wow wow!" << std::endl;
}