#include "../incs/FragTrap.hpp"

FragTrap::FragTrap()
{
    this->_hitPoints 	    = 100;
	this->_energyPoints     = 100;
	this->_attackDamage     = 30;

	std::cout << "FragTrap Default Constructor Called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
    this->_name 			= name;
    this->_hitPoints 	    = 100;
	this->_energyPoints     = 100;
	this->_attackDamage     = 30;

	std::cout << " (FragTrap non-default) constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	*this = other;

	std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& Fragtrap)
{
	if (this != &Fragtrap)
	{
		this->_name 		    = Fragtrap._name;
		this->_hitPoints 	    = Fragtrap._hitPoints;
		this->_energyPoints     = Fragtrap._energyPoints;
		this->_attackDamage     = Fragtrap._attackDamage;
	}

	std::cout << "FragTrap Copy assignment operator called" << std::endl;

	return (*this);
}


void FragTrap::highFivesGuys(void)
{
    std::cout << "[HIGH-FIVE] " << this->_name << " gives you a high five!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << this->_name << " FragTrap called destructor " << std::endl;
}