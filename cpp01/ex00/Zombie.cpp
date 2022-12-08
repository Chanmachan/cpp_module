#include "Zombie.hpp"

Zombie::Zombie() {

}

Zombie::~Zombie() {
	std::cout << name << "Destroyed" << std::endl;
}

//Use this to access members of a class object
Zombie::Zombie(std::string name) {
	this->name = name;
}

void Zombie::announce() {
	std::cout << name <<": BraiiiiiiinnnzzzZ..." << std::endl;
}