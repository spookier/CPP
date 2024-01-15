#include "../incs/Animal.hpp"

Animal::Animal()
{
    this->_type = "[BASE-CLASS]";

    std::cout << this->_type << " Constructor called" << std::endl;
}

Animal::Animal(const Animal &other) 
{
    *this = other;

    std::cout << this->_type << " Copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }

    std::cout << this->_type << " Copy assignment operator called" << std::endl;

    return (*this);
}

void Animal::makeSound(void) const
{
    std::cout << "..." << std::endl;
}


Animal::~Animal()
{
    std::cout << this->_type << " Destructor called" << std::endl;
}