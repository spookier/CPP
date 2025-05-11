#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <stack>
#include <iostream>
#include <list>

template <typename T>
class MutantStack: public std::stack<T>
{
    public:
        MutantStack() {}
        MutantStack(const MutantStack &other)
        {
            *this = other;
        }
        MutantStack& operator=(const MutantStack &other)
        {
            if (this == &other)
                return (*this);
            std::stack<T>::operator=(other);
            return (*this);
        }
        ~MutantStack() {}


        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin()
        {
            return (std::stack<T>::c.begin());
        }
        iterator end()
        {
            return (std::stack<T>::c.end());
        }

};

#endif