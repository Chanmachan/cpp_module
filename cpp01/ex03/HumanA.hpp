//
// Created by 本間優之介 on 2022/12/09.
//

#ifndef CPP_MODULE_HUMANA_HPP
#define CPP_MODULE_HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
private:
	std::string	_name;
	Weapon		&_weapon;
public:
	HumanA(std::string name, Weapon &weapon);
	void	attack();
	~HumanA();
};


#endif //CPP_MODULE_HUMANA_HPP
