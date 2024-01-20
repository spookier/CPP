#include "../incs/AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const &type)
{
    this->_type = type;
}

AMateria &AMateria::operator=(const AMateria &other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    return (*this);
}

std::string const &AMateria::getType() const
{
    return (this->_type);
}

void AMateria::use(ICharacter &target)
{
    std::cout << "AMateria used on: " << target.getName() << std::endl;
}

AMateria::~AMateria() {}

