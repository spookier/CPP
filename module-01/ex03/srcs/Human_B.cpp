#include "Human_B.hpp"

Human_B::Human_B(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

void Human_B::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void Human_B::attack()
{
	if (this->weapon)
		std::cout << this->name << "attacks with his " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " attacks with his hands! " << std::endl;
}

Human_B::~Human_B()
{

}

