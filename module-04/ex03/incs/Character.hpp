#ifndef CHARACTER_H
# define CHARACTER_H

#include "ICharacter.hpp"

class Character : public ICharacter
{
    public:
    	Character(std::string const &name);
	    Character(const Character &other);
	    Character &operator=(const Character &other);
        virtual ~Character();

        virtual std::string const &getName() const;
        virtual void equip(AMateria *m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter &target);

    private:
        Character();
        std::string _name;
        AMateria *_materias[4];
};

#endif