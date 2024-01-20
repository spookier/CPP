#ifndef CURE_H
# define CURE_H

#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure &other);
        Cure &operator=(const Cure &other);
        ~Cure();

        virtual AMateria *clone() const;
        virtual void use(ICharacter &target);
};


#endif