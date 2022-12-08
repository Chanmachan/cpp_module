#include "Zombie.hpp"

int main(){
	std::cout << "================heap================" << std::endl;
	Zombie	*heap_zombie = newZombie("heap ");

	heap_zombie->announce();
	delete heap_zombie;

	std::cout << "================stack===============" << std::endl;
	Zombie	stack_zombie1;
	randomChump("randomChump ");
}
