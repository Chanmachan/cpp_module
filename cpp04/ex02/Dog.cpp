//
// Created by 本間優之介 on 2023/02/18.
//

#include "Dog.h"

Dog::Dog(): Animal("Dog"), brains_(new (std::nothrow) Brain()) {
	std::cout << "Dog " << type << " Constructor called" << std::endl;
}

Dog::Dog(const Dog &src)  : Animal(src), brains_(NULL) {
	std::cout << "Dog " << type << " Copy Constructor called"<< std::endl;
	*this = src;
}

Dog::~Dog() {
	std::cout << "Dog " << type << " Destructor called" << std::endl;
	// deleteはfreeと違ってNULLでも問題ない
	delete brains_;
}

Dog& Dog::operator=(const Dog &src) {
	std::cout << "Dog " << this->type << " operator= called" << std::endl;
	if (this != &src) {
		this->type = src.type;
		if (this->brains_) {
			*this->brains_ = *src.brains_;
		} else {
			this->brains_ = new Brain(*src.brains_);
		}
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Bow wow wow!" << std::endl;
}

void Dog::setBrain() {
	brains_->setBrain();
}

std::string Dog::getBrain(size_t i) const {
	return brains_->getBrain(i);
}