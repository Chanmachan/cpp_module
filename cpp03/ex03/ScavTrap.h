//
// Created by 本間優之介 on 2023/02/16.
//

#ifndef CPP03EX00_SCAVTRAP_H
#define CPP03EX00_SCAVTRAP_H

#include "ClapTrap.h"

class ScavTrap: public virtual ClapTrap{
public:
	const static unsigned int init_hp = 100;
	const static unsigned int init_ep = 50;
	const static unsigned int init_ad = 20;

	ScavTrap();
	explicit ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& src);
	~ScavTrap();

	ScavTrap& operator=(const ScavTrap& src);

	void attack(const std::string& target);
	void guardGate();
};


#endif //CPP03EX00_SCAVTRAP_H
