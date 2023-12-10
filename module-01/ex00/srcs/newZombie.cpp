#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *zombie_allocated;

	zombie_allocated = new Zombie(name);

	return(zombie_allocated);
}