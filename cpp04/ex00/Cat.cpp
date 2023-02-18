//
// Created by 本間優之介 on 2023/02/18.
//

#include "Cat.h"

Cat::Cat(): Animal("Cat") {
	std::cout << "Hi Cat !" << std::endl;
}

Cat::Cat(const Cat &src)  : Animal(src) {
	std::cout << "Cat " << this->type << " is duplicated"<< std::endl;
	Animal::type = src.Animal::type;
}

Cat::~Cat() {
	std::cout << "Bye Cat !" << std::endl;
}

Cat& Cat::operator=(const Cat &src) {
	this->Animal::type = src.Animal::type;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}