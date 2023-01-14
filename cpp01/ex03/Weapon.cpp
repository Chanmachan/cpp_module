//
// Created by 本間優之介 on 2022/12/09.
//

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->_type = type;
}

const std::string& Weapon::getType() {
	return (_type);
}

void Weapon::setType(std::string type) {
	this->_type = type;
}
