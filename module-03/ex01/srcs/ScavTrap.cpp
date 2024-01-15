#include "../incs/ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->_hitPoints 	    = 100;
	this->_energyPoints     = 50;
	this->_attackDamage     = 20;
    this->_gate_keeper_mode = false;

	std::cout << "ScavTrap Default Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
    this->_name 			= name;
    this->_hitPoints 	    = 100;
	this->_energyPoints     = 50;
	this->_attackDamage     = 20;
    this->_gate_keeper_mode = false;

	std::cout << " (ScavTrap non-default) constructor Called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	*this = other; 							

	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavtrap)
{
	if (this != &scavtrap)
	{
		this->_name 		    = scavtrap._name;
		this->_hitPoints 	    = scavtrap._hitPoints;
		this->_energyPoints     = scavtrap._energyPoints;
		this->_attackDamage     = scavtrap._attackDamage;
        this->_gate_keeper_mode = scavtrap._gate_keeper_mode;
	}

	std::cout << "ScavTrap Copy assignment operator called" << std::endl;

	return (*this);
}

void ScavTrap::attack(const std::string &target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "[SCAVTRAP] " << this->_name << " impossible to attack, not enough energy points..." << std::endl;
	}
	else if (this->_hitPoints <= 0)
	{
		std::cout << "[SCAVTRAP] " <<  this->_name << " impossible to attack, source is dead..." << std::endl;
	}
	else
	{
		std::cout << "[SCAVTRAP] " << this->_name << " attacks " << target << 
		" causing " << this->_attackDamage << " damage!" << std::endl;

		this->_energyPoints--;
	}
}

void ScavTrap::guardGate(void)
{
	if (this->_gate_keeper_mode == false)
	{
		this->_gate_keeper_mode = true;
		std::cout << "[GUARD MODE] " << this->_name << " is now in Gate keeper mode" << std::endl;
	}
	else
	{
		std::cout << "[GUARD MODE] " << this->_name << " is already in Gate Keeper mode" << std::endl;
	}
}

ScavTrap::~ScavTrap() 
{
	std::cout << this->_name << " ScavTrap called ~destructor" << std::endl;
}
