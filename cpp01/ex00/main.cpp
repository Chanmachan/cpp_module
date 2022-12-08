#include "Zombie.hpp"

int main(){
	std::cout << "================heap================" << std::endl;
	Zombie	*heap_zombie = newZombie("heap ");

	if (heap_zombie)
		heap_zombie->announce();
	else
		return (1);
	delete heap_zombie;

	std::cout << "================stack===============" << std::endl;
	Zombie	stack_zombie1;
	randomChump("randomChump ");
}
