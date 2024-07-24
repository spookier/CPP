#include "../incs/Intern.hpp"
#include "../incs/AForm.hpp"

#include <iostream>

int main()
{
    Intern someRandomIntern;
    AForm* rrf;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf)
    {
        std::cout << "Form created successfully" << std::endl;
        delete rrf;
    }
    else
    {
        std::cout << "Form creation failed" << std::endl;
    }

    // rrf = someRandomIntern.makeForm("invalid form", "01010101010");
    // if (rrf)
    // {
    //     std::cout << "Form created successfully" << std::endl;
    //     delete rrf;
    // }
    // else
    // {
    //     std::cout << "Form creation failed" << std::endl;
    // }

	return(0);
}