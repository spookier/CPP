#include "../incs/AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const &type) {}

AMateria &AMateria::operator=(const AMateria &other) {}

std::string const &AMateria::getType() const
{
    return(this->_type);
}

AMateria *AMateria::clone() const {}

void AMateria::use(ICharacter &target) {}

AMateria::~AMateria() {}

