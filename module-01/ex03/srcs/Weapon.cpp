#include "../incs/Weapon.hpp"

Weapon::Weapon(std::string type)
{
	setType(type);
}

void Weapon::setType(const std::string &type)
{
	this->type = type;
}

const std::string& Weapon::getType() const
{
    return (this->type);
}


Weapon::~Weapon()
{

}