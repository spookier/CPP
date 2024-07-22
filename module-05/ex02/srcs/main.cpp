#include "../incs/Bureaucrat.hpp"
#include "../incs/ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
    try
    {
        // Create bureaucrats
        Bureaucrat lowRank("Intern", 150);
        Bureaucrat midRank("Manager", 50);

        // Create form
        ShrubberyCreationForm shrubForm("garden");

        std::cout << "\n--- Testing ShrubberyCreationForm ---\n";
        std::cout << shrubForm << std::endl;
        lowRank.signForm(shrubForm);  // Should fail
        midRank.signForm(shrubForm);  // Should succeed
        lowRank.executeForm(shrubForm);  // Should fail
        midRank.executeForm(shrubForm);  // Should succeed



        // ----------------------------------------
        


    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}