#ifndef ICHARACTER_H
# define ICHARACTER_H

#include "AMateria.hpp"


/*

Circular Dependency
if AMateria.hpp includes ICharacter.hpp and vice versa will cause compilation error

By using a forward declaration, you break the cycle
*/

// this is a forward declaration
class AMateria; 

class ICharacter
{
    public:
        virtual ~ICharacter() {}
        virtual std::string const &getName() const      = 0;
        virtual void equip(AMateria *m)                 = 0;
        virtual void unequip(int idx)                   = 0;
        virtual void use(int idx, ICharacter &target)   = 0;
};


#endif