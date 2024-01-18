#ifndef AMATERIA_H
# define AMATERIA_H

#include <string>

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
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter &target);
};

#endif