//
// Created by 本間優之介 on 2023/02/17.
//

#ifndef CPP03EX02_FRAGTRAP_H
#define CPP03EX02_FRAGTRAP_H

#include "ClapTrap.h"

class FragTrap: public virtual ClapTrap {
private:
	const static unsigned int init_hp = 100;
	const static unsigned int init_ep = 100;
	const static unsigned int init_ad = 30;
public:
	FragTrap();
	explicit FragTrap(const std::string& name);
	FragTrap(const FragTrap& src);
	~FragTrap();

	FragTrap& operator=(const FragTrap& src);

	void attack(const std::string& target);
	void highFivesGuys(void);
};


#endif //CPP03EX02_FRAGTRAP_H
