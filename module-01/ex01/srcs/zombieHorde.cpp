#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{	
	Zombie *hordeZombies;
	int i;

	i = 0;
	hordeZombies = new Zombie[N];
	while(i < N)
	{
		hordeZombies[i].set_name(name);
		i++;
	}

	return(hordeZombies);
}