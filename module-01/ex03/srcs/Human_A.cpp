#include "Human_A.hpp"

Human_A::Human_A(std::string name, Weapon &weapon) : weapon(weapon)
{
	
	this->weapon = weapon; // Redundant, already set by the initializer ( : weapon(weapon) )
	this->name = name;
}

void Human_A::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}

Human_A::~Human_A()
{

}