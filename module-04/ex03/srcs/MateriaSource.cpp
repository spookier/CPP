#include "../incs/MateriaSource.hpp"

/*
Character class uses its priv array to store equipped materias, up to 4 slots
> like an inventory

The MateriaSource class uses its priv array to store materia templates
>These templates are used to create new materias (shadow, fire, etc..)
*/

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++) // Initializing every template of materia to NULL
    {
        this->_sources[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    *this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            this->_sources[i] = other._sources[i];
        }
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_sources[i] == NULL)
        {
            this->_sources[i] = m;
            std::cout << "Learned new materia: " << this->_sources[i]->getType() << std::endl;
            return ;
        }
    }
}

/*
Let’s say learnMateria has been called before to learn two types of materia: "ice" and "cure"

when createMateria("ice") is called, it searches through its priv array "sources"
if it finds the "cure" materia, it clones this materia and returns the new clone

if createMateria("fire") is called and "fire" doesnt exist, it returns 0

for short: this function is for creating new instances of these known materias
*/

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if(this->_sources[i] != NULL && this->_sources[i]->getType() == type)
        {
            return (this->_sources[i]->clone());
        }
    }
    return (0);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_sources[i] != NULL)
            delete this->_sources[i];
	}
}