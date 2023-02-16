//
// Created by 本間優之介 on 2023/02/15.
//

#ifndef CPP03EX00_CLAPTRAP_H
#define CPP03EX00_CLAPTRAP_H

#include <iostream>

class ClapTrap {
private:
	std::string name_;
	unsigned int hit_point_;
	unsigned int energy_point_;
	unsigned int attack_damage_;

	const static unsigned int hp = 10;
	const static unsigned int ep = 10;
	const static unsigned int ad = 0;
public:
	ClapTrap();
	explicit ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& src);
	~ClapTrap();

	ClapTrap& operator=(const ClapTrap& source);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	const std::string& get_name() const;
	unsigned int get_hit_point() const;
	unsigned int get_energy_point() const;
	unsigned int get_attack_damage() const;
};


#endif //CPP03EX00_CLAPTRAP_H
