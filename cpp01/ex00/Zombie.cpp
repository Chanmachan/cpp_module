#include "Zombie.hpp"

Zombie::Zombie() {

}

Zombie::~Zombie() {
	std::cout << _name << "Destroyed" << std::endl;
}

//Use this to access members of a class object
Zombie::Zombie(std::string name) {
	this->_name = name;
}

void Zombie::announce() {
	std::cout << _name <<": BraiiiiiiinnnzzzZ..." << std::endl;
}