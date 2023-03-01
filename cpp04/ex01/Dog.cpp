//
// Created by 本間優之介 on 2023/02/18.
//

#include "Dog.h"

Dog::Dog(): Animal("Dog"), brains_(new (std::nothrow) Brain()) {
	std::cout << "Dog " << type << " Constructor called" << std::endl;
}

Dog::Dog(const Dog &src)  : Animal(src) {
	std::cout << "Dog " << type << " Copy Constructor called"<< std::endl;
	this->type = src.type;
	// srcのbrains_を複製 -> ()必要？*(src.brains_)
	if (src.brains_) {
		brains_ = new (std::nothrow) Brain(*src.brains_);
	}
}

Dog::~Dog() {
	std::cout << "Dog " << type << " Destructor called" << std::endl;
	// deleteはfreeと違ってNULLでも問題ない
	delete brains_;
}

Dog& Dog::operator=(const Dog &src) {
	std::cout << "Dog " << this->type << " operator= called" << std::endl;
	this->type = src.type;
	if (src.brains_) {
		this->brains_ = new(std::nothrow) Brain(*src.brains_);
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Bow wow wow!" << std::endl;
}