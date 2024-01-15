#include "../incs/WrongCat.hpp"

WrongCat::WrongCat()
{
    this->_type = "WrongCat";

    std::cout << this->_type << " Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    *this = other;

    std::cout << this->_type << " Copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }

    std::cout << this->_type << " Copy operator called" << std::endl;

    return (*this);
}

void WrongCat::makeSound(void) const
{
    std::cout << "jsdakdsajmdsakdsakjdaks" << std::endl;
}

std::string WrongCat::getType(void) const
{
    return (this->_type);
}


WrongCat::~WrongCat()
{
    std::cout << "> [WrongCat] Destructor called" << std::endl;
}
