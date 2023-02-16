//
// Created by 本間優之介 on 2023/02/15.
//

#include "ScavTrap.h"
#include "FragTrap.h"

int main() {
	{
		ScavTrap a("Nobita");
		ScavTrap b;
		ScavTrap c; // ClapTrap c = a; -> operator=は呼ばれない

		c = a;

		std::cout << "---------------------------------------------------------" << std::endl;

		a.attack("Shizuka");

		std::cout << "---------------------------------------------------------" << std::endl;

		std::cout << "1.HP: " << a.get_hit_point() << std::endl;
		for (size_t i = 1; i < 4; i++) {
			a.takeDamage(i * 30);
			std::cout << "[" << i << "]" << "After attack HP: " << a.get_hit_point() << std::endl;
			a.beRepaired(i * 20);
			std::cout << "[" << i << "]" << "After repair HP: " << a.get_hit_point() << std::endl;
		}

		std::cout << "---------------------------------------------------------" << std::endl;

		std::cout << "2.HP: " << b.get_hit_point() << std::endl;
		for (size_t i = 1; i < 4; i++) {
			b.takeDamage(i * 30);
			std::cout << "[" << i << "]" << "After attack HP: " << b.get_hit_point() << std::endl;
			b.beRepaired(i * 20);
			std::cout << "[" << i << "]" << "After repair HP: " << b.get_hit_point() << std::endl;
		}

		std::cout << "---------------------------------------------------------" << std::endl;

		std::cout << "3.HP: " << c.get_hit_point() << std::endl;
		for (size_t i = 1; i < 4; i++) {
			c.takeDamage(i * 30);
			std::cout << "[" << i << "]" << "After attack HP: " << c.get_hit_point() << std::endl;
			c.beRepaired(i * 20);
			std::cout << "[" << i << "]" << "After repair HP: " << c.get_hit_point() << std::endl;
		}

		std::cout << "---------------------------------------------------------" << std::endl;

		a.guardGate();

		std::cout << "---------------------------------------------------------" << std::endl;
	}

	/* FlagTrap test */
	{

		std::cout << "---------------------------------------------------------" << std::endl << std::endl;

		std::cout << "######################" << std::endl;
		std::cout << "#    FragTrap TEST   #" << std::endl;
		std::cout << "######################" << std::endl << std::endl;

		FragTrap d;
		FragTrap e("Doraemon");
		FragTrap f;
		FragTrap g(e);

		f = d;

		std::cout << "---------------------------------------------------------" << std::endl;

		d.attack("Shizuka");

		std::cout << "---------------------------------------------------------" << std::endl;

		std::cout << "4.HP: " << d.get_hit_point() << std::endl;
		for (size_t i = 1; i < 4; i++) {
			d.takeDamage(i * 30);
			std::cout << "[" << i << "]" << "After attack HP: " << d.get_hit_point() << std::endl;
			d.beRepaired(i * 20);
			std::cout << "[" << i << "]" << "After repair HP: " << d.get_hit_point() << std::endl;
		}

		std::cout << "---------------------------------------------------------" << std::endl;

		std::cout << "5.HP: " << e.get_hit_point() << std::endl;
		for (size_t i = 1; i < 4; i++) {
			e.takeDamage(i * 30);
			std::cout << "[" << i << "]" << "After attack HP: " << e.get_hit_point() << std::endl;
			e.beRepaired(i * 20);
			std::cout << "[" << i << "]" << "After repair HP: " << e.get_hit_point() << std::endl;
		}

		std::cout << "---------------------------------------------------------" << std::endl;

		std::cout << "6.HP: " << f.get_hit_point() << std::endl;
		for (size_t i = 1; i < 4; i++) {
			f.takeDamage(i * 30);
			std::cout << "[" << i << "]" << "After attack HP: " << f.get_hit_point() << std::endl;
			f.beRepaired(i * 20);
			std::cout << "[" << i << "]" << "After repair HP: " << f.get_hit_point() << std::endl;
		}

		std::cout << "---------------------------------------------------------" << std::endl;

		std::cout << "7.HP: " << g.get_hit_point() << std::endl;
		for (size_t i = 1; i < 4; i++) {
			g.takeDamage(i * 30);
			std::cout << "[" << i << "]" << "After attack HP: " << g.get_hit_point() << std::endl;
			g.beRepaired(i * 20);
			std::cout << "[" << i << "]" << "After repair HP: " << g.get_hit_point() << std::endl;
		}

		std::cout << "---------------------------------------------------------" << std::endl;

		d.highFivesGuys();

		std::cout << "---------------------------------------------------------" << std::endl;
	}
}
