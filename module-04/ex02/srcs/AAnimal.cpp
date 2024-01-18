#include "../incs/AAnimal.hpp"

AAnimal::AAnimal() {}

AAnimal::AAnimal(const AAnimal &other)
{
    (void)&other;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
    (void)other;
    return (*this);
}

void AAnimal::makeSound(void) const
{
    std::cout << "..." << std::endl;
}

std::string AAnimal::getType(void) const
{
    return (this->_type);
}

AAnimal::~AAnimal()
{
    std::cout << "[BASE] Destructor called" << std::endl;
}