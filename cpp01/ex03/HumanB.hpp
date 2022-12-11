//
// Created by 本間優之介 on 2022/12/09.
//

#ifndef CPP_MODULE_HUMANB_HPP
#define CPP_MODULE_HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
	std::string	_name;
	Weapon		*_weapon;
public:
	HumanB(std::string name);
	void	setWeapon(Weapon &weapon);
	void	attack();
};


#endif //CPP_MODULE_HUMANB_HPP
