#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	// Subject doesn't specify what to use as a default name
	// So _name = empty string (length = 0) when initialized with a default constructor
	
	this->_hitPoints 	= 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;

	std::cout << "Default Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->_name 		= name;
	this->_hitPoints 	= 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;

	std::cout << this->_name << " (non-default) constructor called " << std::endl;
}


ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;

	std::cout << "Copy constructor called" << std::endl;
}


ClapTrap& ClapTrap::operator=(const ClapTrap& claptrap)
{
	if (this != &claptrap)
	{
		this->_name 		= claptrap._name;
		this->_hitPoints 	= claptrap._hitPoints;
		this->_energyPoints = claptrap._energyPoints;
		this->_attackDamage = claptrap._attackDamage;
	}

	std::cout << "Copy assignment operator called" << std::endl;

	return (*this);
}


void ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "Impossible to attack, not enough energy points..." << std::endl;
	}
	else if (this->_hitPoints <= 0)
	{
		std::cout << "Impossible to attack, source is dead..." << std::endl;
	}
	else
	{
		std::cout << this->_name << " attacks " << target << 
		" causing " << this->_attackDamage << " damage!" << std::endl;

		this->_energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > 0)
	{
		std::cout << this->_name << " took " << amount << " damage!" << std::endl;
		this->_hitPoints -= amount;
		std::cout << "(" << this->_name << "'s health after taking damage = " << this->_hitPoints << ")" << std::endl;
	}
	else
	{
		std::cout << "Impossible to take damage, source is already dead..." << std::endl;
	}

}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0)
	{
		std::cout << this->_name << "got repaired !" << std::endl;
		this->_energyPoints--;
		this->_hitPoints += amount;
	}
	else
	{
		std::cout << "Impossible to repair, not enough energy points..." << std::endl;
	}

}

ClapTrap::~ClapTrap()
{
	std::cout << this->_name << " called ~destructor" << std::endl;
}
