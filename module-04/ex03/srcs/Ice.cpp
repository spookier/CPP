#include "../incs/Ice.hpp"

Ice::Ice() : AMateria("ice")
{

}

Ice::Ice(const Ice &other) : AMateria(other)
{
    *this = other;
}

Ice &Ice::operator=(const Ice &other)
{
    if (this != &other)
    {
        AMateria::operator=(other);
    }
    return (*this);
}

AMateria *Ice::clone() const
{
    Ice *newIce = new Ice(*this);
    return (newIce);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}


Ice::~Ice()
{

}
