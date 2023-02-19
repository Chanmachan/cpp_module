//
// Created by 本間優之介 on 2023/02/18.
//

#include "WrongCat.h"

WrongCat::WrongCat(): WrongAnimal("WrongCat") {
	std::cout << "Hi WrongCat !" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src)  : WrongAnimal(src) {
	std::cout << "WrongCat " << this->type << " is duplicated"<< std::endl;
	WrongAnimal::type = src.WrongAnimal::type;
}

WrongCat::~WrongCat() {
	std::cout << "Bye WrongCat !" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &src) {
	this->WrongAnimal::type = src.WrongAnimal::type;
	return *this;
}

// 呼ばれない
void WrongCat::makeSound() const {
	std::cout << "Yondeeeeeeeeee!" << std::endl;
}