//
// Created by 本間優之介 on 2023/02/18.
//

#include "Cat.h"

Cat::Cat(): Animal("Cat") {
	std::cout << "Cat " << type << " Constructor called" << std::endl;
}

Cat::Cat(const Cat &src)  : Animal(src) {
	std::cout << "Cat " << type << " Copy Constructor called"<< std::endl;
}

Cat::~Cat() {
	std::cout << "Cat " << type << " Destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &src) {
	std::cout << "Cat " << this->type << " operator= called" << std::endl;
	if (this != &src) {
		this->type = src.type;
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}