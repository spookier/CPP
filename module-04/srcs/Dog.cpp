#include "../incs/Dog.hpp"

Dog::Dog()
{
    this->_type = "Dog";

    std::cout << this->_type << " Constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    *this = other;

    std::cout << this->_type << " Copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }

    std::cout << this->_type << " Copy operator called" << std::endl;

    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "Woof Woof !" << std::endl;
}

std::string Dog::getType(void) const
{
    return (this->_type);
}

Dog::~Dog()
{
    std::cout << "> [DOG] Destructor called" << std::endl;
}
