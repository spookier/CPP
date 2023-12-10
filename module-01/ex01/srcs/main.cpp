#include "Zombie.hpp"

int main(void)
{
	int i;
	int N;
	Zombie *horde;

	i = 0;
	N = 5;
	horde = zombieHorde(N, "zoomer");
	while(i < N)
	{
		horde[i].announce();
		i++;
	}
	delete[] horde;
	return(0);
}