//
// Created by 本間優之介 on 2023/02/17.
//

#ifndef CPP03EX03_DIAMONDTRAP_H
#define CPP03EX03_DIAMONDTRAP_H

#include "FragTrap.h"
#include "ScavTrap.h"

class DiamondTrap: public FragTrap, public ScavTrap{
private:
	std::string name_;
	DiamondTrap();
public:
	explicit DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& src);
	~DiamondTrap();

	DiamondTrap& operator=(const DiamondTrap& src);

	void attack(const std::string& target);
	void whoAmI();

	const static unsigned int init_hp = FragTrap::init_hp; // 100
	const static unsigned int init_ep = ScavTrap::init_ep; // 50
	const static unsigned int init_ad = FragTrap::init_ad; // 30
};


#endif //CPP03EX03_DIAMONDTRAP_H
