#ifndef AMATERIA_H
# define AMATERIA_H

#include <string>
#include <iostream>

#include "ICharacter.hpp"


/*

Circular Dependency
if AMateria.hpp includes ICharacter.hpp and vice versa, it will cause compilation error

By using a forward declaration, you break the cycle
*/

// this is a forward declaration
class ICharacter;

class AMateria
{
    private:
        AMateria();

    protected:
        std::string _type;

    public:
        AMateria(std::string const &type);
        AMateria &operator=(const AMateria &other);
        virtual ~AMateria();

        std::string const &getType() const; //Returns the materia type
        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);
};

#endif