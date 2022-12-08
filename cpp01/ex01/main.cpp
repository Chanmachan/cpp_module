#include "Zombie.hpp"

/*__attribute__((destructor))
static void destructor() {
	system("leaks -q zombieHorde");
}*/

int main(){
	int	N = 5;
	Zombie	*zombie_horde = zombieHorde(N, "(「 ﾟρﾟ)「 ");
	if (zombie_horde == NULL)
		return (1);

	for (int i = 0; i < N; i++){
		std::cout << "[" << i + 1 << "] ";
		zombie_horde[i].announce();
	}
	delete [] zombie_horde;
}
