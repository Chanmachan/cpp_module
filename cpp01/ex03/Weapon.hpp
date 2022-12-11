//
// Created by 本間優之介 on 2022/12/09.
//

#ifndef CPP_MODULE_WEAPON_HPP
#define CPP_MODULE_WEAPON_HPP

#include <iostream>

class Weapon {
private:
	std::string	_type;
public:
	Weapon();
	Weapon(std::string type);
//	~Weapon();
	std::string	getType();
	void	setType(std::string type);
};

#endif //CPP_MODULE_WEAPON_HPP
