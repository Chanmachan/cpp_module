/* Horde means a large group of people */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){
	Zombie	*zombie_horde = new (std::nothrow) Zombie[N];

	if (!zombie_horde)
		return (NULL);
	for (int i = 0; i < N; i++){
		zombie_horde[i].set_name(name);
	}
	return (zombie_horde);
}
