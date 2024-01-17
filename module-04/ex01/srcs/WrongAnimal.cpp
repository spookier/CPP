#include "../incs/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    this->_type = "WrongAnimal";

    std::cout << this->_type << " Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    *this = other;

    std::cout << this->_type << " Copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }

    std::cout << this->_type << " Copy operator called" << std::endl;

    return (*this);
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "*WRONG ANIMAL NOISE*" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (this->_type);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "> [WrongAnimal] Destructor called" << std::endl;
}
