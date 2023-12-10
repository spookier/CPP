#include "Zombie.hpp"

int main(void)
{
	Zombie stack_z("Stack Zombie");
	Zombie *heap_z = newZombie("Heap Zombie");
	randomChump("Random zombie");
	
	stack_z.announce();
	heap_z->announce();
	
	delete heap_z;
}