//
// Created by 本間優之介 on 2023/02/18.
//

#include "Dog.h"

Dog::Dog(): Animal("Dog") {
	std::cout << "Hi Dog !" << std::endl;
}

Dog::Dog(const Dog &src)  : Animal(src) {
	std::cout << "Dog " << this->type << " is duplicated"<< std::endl;
	Animal::type = src.Animal::type;
}

Dog::~Dog() {
	std::cout << "Bye Dog !" << std::endl;
}

Dog& Dog::operator=(const Dog &src) {
	this->Animal::type = src.Animal::type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Bow wow wow!" << std::endl;
}