#ifndef AANIMAL_H
#define AANIMAL_H

#include <string>
#include <iostream>

class AAnimal
{
    // Put the constructor as protected to remove direct instantiation
    // then put ""= 0" to have an abstract class (its required to have one)

    protected:
        std::string _type;
        AAnimal();
        AAnimal(const AAnimal &other);
        AAnimal &operator=(const AAnimal &other);

    public:
        virtual ~AAnimal();

        virtual void makeSound(void) const      = 0;
        virtual std::string getType(void) const = 0;
};

#endif