#include "../incs/Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("John", 1);
        std::cout << b1 << std::endl;
        
        Bureaucrat b2("Jane", 150);
        std::cout << b2 << std::endl;

        b1.decrementGrade();
        std::cout << b1 << std::endl;

        b2.incrementGrade();
        std::cout << b2 << std::endl;

        Bureaucrat b3("Chloe", 1);  
        std::cout << b3 << std::endl;
        b3.incrementGrade(); // This will throw an exception, you're trying to increase rank to 0
    }
    catch (std::exception &err)
    {
        std::cout << "[TEST 1] Exception: " << err.what() << std::endl;
    }

    // try
    // {
    //     Bureaucrat b1("Spoolex", 160);
    //     std::cout << b1 << std::endl;
    // }
    // catch (std::exception &err)
    // {
    //     std::cout << "[TEST 2] Exception: " << err.what() << std::endl;
    // }

    // try
    // {
    //     Bureaucrat b1("Chick", -10);
    //     std::cout << b1 << std::endl;
    // }
    // catch (std::exception &err)
    // {
    //     std::cout << "[TEST 3] Exception: " << err.what() << std::endl;
    // }


    return (0);
}