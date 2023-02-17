//
// Created by 本間優之介 on 2023/02/15.
//

#include "DiamondTrap.h"

int main() {

	std::cout << "---------------------------------------------------------" << std::endl << std::endl;

	std::cout << "###################################################" << std::endl;
	std::cout << "#     Testing the order in which constructors     #" << std::endl <<
				 "#         and destructors are called              #" << std::endl;
	std::cout << "###################################################" << std::endl << std::endl;
	// SCOPE1
	{
		//DiamondTrap error; // デフォルトコンストラクタをprivate属性にしているため
		DiamondTrap a("robot1");
	}

	std::cout << "---------------------------------------------------------" << std::endl << std::endl;

	std::cout << "##################################################" << std::endl;
	std::cout << "#                  DEFAULT TEST                  #" << std::endl;
	std::cout << "##################################################" << std::endl << std::endl;
	// SCOPE2
	{
		DiamondTrap a("robot2");
		DiamondTrap b("robot3");
		DiamondTrap c("robot4");

		b = c;

		std::cout << std::endl;

		a.attack("enemy");
		c.whoAmI();
		b.whoAmI(); // ClapTrapのほうがoperator=で更新できてない？けどそもそも必要ある？

		std::cout << std::endl;

		for (size_t i = 1; i < 4; i++) {
			a.takeDamage(i * 30);
			std::cout << "[" << i << "]" << "After attack HP: " << a.get_hit_point() << std::endl;
			std::cout << "[" << i << "]" << "After attack EP: " << a.get_energy_point() << std::endl;
			a.beRepaired(i * 20);
			std::cout << "[" << i << "]" << "After repair HP: " << a.get_hit_point() << std::endl;
			std::cout << "[" << i << "]" << "After repair EP: " << a.get_energy_point() << std::endl;
			std::cout << std::endl;
		}

		std::cout << std::endl;
	}

	std::cout << "---------------------------------------------------------" << std::endl << std::endl;

}
