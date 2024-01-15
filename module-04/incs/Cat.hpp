#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat &other);
        Cat &operator=(const Cat &other);
        ~Cat();                             //override

        void makeSound(void) const;         //override
        std::string getType(void) const;

};


#endif