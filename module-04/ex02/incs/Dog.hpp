#ifndef DOG_H
#define DOG_H

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
    private:
        Brain *_brain;


    public:
        Dog();
        Dog(const Dog &other);
        Dog &operator=(const Dog &other);
        ~Dog(); //override

        void makeSound(void) const; //override
        std::string getType(void) const;

};

#endif