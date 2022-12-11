//
// Created by 本間優之介 on 2022/12/09.
//

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon) {
	std::cout << "HumanA constructor called" << std::endl;
}

void HumanA::attack() {
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}

HumanA::~HumanA() {
	std::cout << "HumanA destructor called" << std::endl;
}