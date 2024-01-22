#include "../incs/Character.hpp"

/*
The Character class uses its array to store equipped materias, up to 4 slots

The MateriaSource class uses its array to store materia templates
These templates are used to create new materias of the same type when requested

*/

Character::Character() {}

Character::Character(std::string const &name)
{
    this->_name = name;

    for (int i = 0; i < 4; i++) // Initializing every materia to NULL at first
    {
        this->_materias[i] = NULL;
    }
}

Character::Character(const Character &other)
{
    *this = other;
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        this->_name = other.getName();
        for (int i = 0; i < 4; i++)
        {
            this->_materias[i] = other._materias[i];
        }
    }
    return (*this);
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_materias[i] == NULL)
        {
            _materias[i] = m;
            std::cout << "Added Materia: " << _materias[i]->getType() << std::endl;
            return ;
        }
    }
    std::cout << "[X] No slot for Materia left !" << std::endl;
}

void Character::unequip(int idx)
{
    if (this->_materias[idx] != NULL)
    {
        std::cout << "Un-equiping: " << this->_materias[idx]->getType() << std::endl;
        delete this->_materias[idx]; 
        this->_materias[idx] = NULL;
    }
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::use(int idx, ICharacter &target)
{
    if ( (idx >= 0 && idx < 4 ) && this->_materias[idx] != NULL)
    {
        this->_materias[idx]->use(target);
    }
    else
        std::cout << "[X] No Materia equipped in slot " << idx << std::endl;

}


// void Character::use(int idx, ICharacter &target)
// {
//     if (idx >= 0 && idx < 4)
//         this->_materias[idx]->use(target);
//     else
//         std::cout << "[X] Invalid itx" << std::endl;
// }

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_materias[i] != NULL)
        {
            delete _materias[i];
        }
    }
}