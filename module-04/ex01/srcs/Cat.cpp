#include "../incs/Cat.hpp"

Cat::Cat()
{
    this->_type = "Cat";
    this->_brain = new Brain();

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

std::string Cat::getType(void) const
{
    return (this->_type);
}

Cat::~Cat()
{
    std::cout << "> [CAT] Destructor called" << std::endl;
    delete this->_brain;
}
