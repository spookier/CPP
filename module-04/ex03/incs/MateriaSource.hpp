#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H


#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &other);
        MateriaSource &operator=(const MateriaSource &other);
        virtual ~MateriaSource();

        virtual void		learnMateria(AMateria* m);
	    virtual AMateria*	createMateria(std::string const& type);

    private:
        AMateria *_sources[4];
};


#endif