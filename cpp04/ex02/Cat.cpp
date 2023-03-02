//
// Created by 本間優之介 on 2023/02/18.
//

#include "Cat.h"

Cat::Cat(): Animal("Cat"), brains_(new (std::nothrow) Brain()) {
	std::cout << "Cat " << type << " Constructor called" << std::endl;
}

Cat::Cat(const Cat &src)  : Animal(src) {
	std::cout << "Cat " << type << " Copy Constructor called"<< std::endl;
	this->type = src.type;
	brains_ = new(std::nothrow) Brain(*src.brains_);
}

Cat::~Cat() {
	std::cout << "Cat " << type << " Destructor called" << std::endl;
	// deleteはfreeと違ってNULLでも問題ない
	delete brains_;
}

Cat& Cat::operator=(const Cat &src) {
	std::cout << "Cat " << this->type << " operator= called" << std::endl;
	if (this != &src) {
		this->type = src.type;
		*this->brains_ = *src.brains_;
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}