//
// Created by 本間優之介 on 2023/02/18.
//

#include "Cat.h"

Cat::Cat(): Animal("Cat"), brains_(new (std::nothrow) Brain()) {
	std::cout << "Hi Cat !" << std::endl;
}

Cat::Cat(const Cat &src)  : Animal(src) {
	std::cout << "Cat " << this->type << " is duplicated"<< std::endl;
	this->Animal::type = src.Animal::type;
	// srcのbrains_を複製 -> ()必要？*(src.brains_)
	if (src.brains_) {
		brains_ = new(std::nothrow) Brain(*src.brains_);
	}
}

Cat::~Cat() {
	std::cout << "Bye Cat !" << std::endl;
	// deleteはfreeと違ってNULLでも問題ない
	delete brains_;
}

Cat& Cat::operator=(const Cat &src) {
	std::cout << "Cat " << this->type << " operator= called" << std::endl;
	this->Animal::type = src.Animal::type;
	if (src.brains_) {
		this->brains_ = new(std::nothrow) Brain(*src.brains_);
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}