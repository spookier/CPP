#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{

}

Cure::Cure(const Cure &other) : AMateria(other)
{
    *this = other;
}

Cure &Cure::operator=(const Cure &other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    return (*this);
}

AMateria *Cure::clone() const
{
    Cure *newCure = new Cure(*this);
    return (newCure);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

Cure::~Cure()
{

}