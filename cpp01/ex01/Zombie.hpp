#ifndef CPP_MODULE_ZOMBIE_HPP
#define CPP_MODULE_ZOMBIE_HPP

#include <iostream>

class Zombie {
private:
	std::string	_name;
public:
	Zombie();
	~Zombie();
	void	announce( void );
	Zombie(std::string name);
	void	set_name(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif //CPP_MODULE_ZOMBIE_HPP
