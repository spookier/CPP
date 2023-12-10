#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string name;

	public:
		Zombie();
		void announce();
		void set_name(std::string name);
		~Zombie();
};

Zombie* zombieHorde(int N, std::string name);
int		main();

#endif