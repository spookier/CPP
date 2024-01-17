#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
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