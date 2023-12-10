#include "Zombie.hpp"

Zombie::Zombie()
{

}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << "Destroyed Zombie: " << this->name << std::endl;
}