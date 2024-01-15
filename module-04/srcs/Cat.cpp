#include "Cat.hpp"

Cat::Cat()
{
    this->_type = "Cat";

    std::cout << this->_type << " Constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    *this = other;

    std::cout << this->_type << " Copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }

    std::cout << this->_type << " Copy operator called" << std::endl;

    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "Meooooowww !" << std::endl;
}

Cat::~Cat()
{
    std::cout << " Destructor called" << std::endl;
}
