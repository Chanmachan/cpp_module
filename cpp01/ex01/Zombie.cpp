#include "Zombie.hpp"

Zombie::Zombie() {

}

Zombie::~Zombie() {
	std::cout << _name << "Destroyed" << std::endl;
}

//Use "this" pointer to access members of a class object
Zombie::Zombie(std::string name) {
	this->_name = name;
}

void Zombie::announce() {
	std::cout << _name <<": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string name) {
	this->_name = name;
}