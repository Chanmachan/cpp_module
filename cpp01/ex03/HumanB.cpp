//
// Created by 本間優之介 on 2022/12/09.
//

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL) {
	std::cout << "HumanB constructor called" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}

void HumanB::attack() {
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " attacks with their " << "(((ꎤ’ω’)و三 ꎤ’ω’)-o≡" << std::endl;
}

HumanB::~HumanB() {
	std::cout << "HumanB destructor called" << std::endl;
}