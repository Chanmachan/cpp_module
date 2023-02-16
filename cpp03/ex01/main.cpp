//
// Created by 本間優之介 on 2023/02/15.
//

#include "ScavTrap.h"

int main() {
	ScavTrap a("Nobita");
	ScavTrap b;
	ScavTrap c; // ClapTrap c = a; -> operator=は呼ばれない

	c = a;

	std::cout << "---------------------------------------------------------" << std::endl;

	a.attack("Shizuka");

	std::cout << "1.HP: " << a.get_hit_point() << std::endl;
	for (size_t i = 1; i < 4; i++) {
		a.takeDamage(i*30);
		std::cout << "[" << i << "]" << "After attack HP: " << a.get_hit_point() << std::endl;
		a.beRepaired(i*20);
		std::cout << "[" << i << "]" <<"After repair HP: " << a.get_hit_point() << std::endl;
	}

	std::cout << "---------------------------------------------------------" << std::endl;

	std::cout << "2.HP: " << b.get_hit_point() << std::endl;
	for (size_t i = 1; i < 4; i++) {
		b.takeDamage(i*30);
		std::cout << "[" << i << "]" << "After attack HP: " << b.get_hit_point() << std::endl;
		b.beRepaired(i*20);
		std::cout << "[" << i << "]" <<"After repair HP: " << b.get_hit_point() << std::endl;
	}

	std::cout << "---------------------------------------------------------" << std::endl;

	std::cout << "3.HP: " << c.get_hit_point() << std::endl;
	for (size_t i = 1; i < 4; i++) {
		c.takeDamage(i*30);
		std::cout << "[" << i << "]" << "After attack HP: " << c.get_hit_point() << std::endl;
		c.beRepaired(i*20);
		std::cout << "[" << i << "]" <<"After repair HP: " << c.get_hit_point() << std::endl;
	}

	std::cout << "---------------------------------------------------------" << std::endl;

	a.guardGate();
}
