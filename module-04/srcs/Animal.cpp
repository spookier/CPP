#include "../incs/Animal.hpp"

Animal::Animal()
{
    this->_type = "BASE";

    std::cout << "[BASE] Constructor called" << std::endl;
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

std::string Animal::getType(void) const
{
    return (this->_type);
}

Animal::~Animal()
{
    std::cout << "[BASE] Destructor called" << std::endl;
}