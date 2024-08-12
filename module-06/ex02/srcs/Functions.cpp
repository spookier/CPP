// functions.cpp
#include "../incs/Functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
    srand(time(0));
    int random = rand() % 3;
    if(random == 0)
        return (new A());
    else if(random == 1)
        return (new B());
    else if(random == 2)
        return (new C());
    else
        return (NULL);
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Object is A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Object is B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Object is C" << std::endl;
    else
        std::cout << "[ERROR] UNKNOWN TYPE" << std::endl;
}

void identify(Base &p)
{
	Base base;

	try
	{
		base = dynamic_cast<A&>(p);
		std::cout << "Object is A" << std::endl;
	}
	catch (std::exception &e){}

	try
	{
		base = dynamic_cast<B&>(p);
		std::cout << "Object is B" << std::endl;
	}
	catch (std::exception &e){}

	try
	{
		base = dynamic_cast<C&>(p);
		std::cout << "Object is C" << std::endl;
	}
	catch (std::exception &e){}
}