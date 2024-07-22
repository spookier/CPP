#include "../incs/Bureaucrat.hpp"
#include "../incs/ShrubberyCreationForm.hpp"
#include "../incs/RobotomyRequestForm.hpp"
#include <iostream>

int main()
{
	try
	{
		// Create bureaucrats of different ranks
		Bureaucrat lowRank("Intern", 150);
		Bureaucrat midRank("Manager", 50);
		Bureaucrat highRank("CEO", 1);


		// ------------------------------------------------------

		std::cout << "\n--- Testing ShrubberyCreationForm ---\n";
		ShrubberyCreationForm shrubForm("home");
		std::cout << shrubForm << std::endl;

		
		lowRank.signForm(shrubForm); // Should fail (grade too low)
		midRank.signForm(shrubForm); // Should succeed

		lowRank.executeForm(shrubForm); // Should fail (grade too low)
		midRank.executeForm(shrubForm); // Should succeed (create _shrubbery file)

		// ------------------------------------------------------

		// std::cout << "\n--- Testing RobotomyRequestForm ---\n";
		// RobotomyRequestForm robotForm("Bender");
		// std::cout << robotForm << std::endl;

		// midRank.signForm(robotForm);  // Should fail (grade too low)
		// highRank.signForm(robotForm); // Should succeed

		// midRank.executeForm(robotForm);	 // Should fail (grade too low)
		// highRank.executeForm(robotForm); // Should succeed (50% chance of robotomization)

		// ------------------------------------------------------

		// std::cout << "\n--- Testing PresidentialPardonForm ---\n";
		// PresidentialPardonForm pardonForm("Zaphod");
		// std::cout << pardonForm << std::endl;

		// midRank.signForm(pardonForm);  // Should fail (grade too low)
		// highRank.signForm(pardonForm); // Should succeed

		// midRank.executeForm(pardonForm);  // Should fail (grade too low)
		// highRank.executeForm(pardonForm); // Should succeed (pardon Zaphod)

		// std::cout << "\n--- Testing execution of unsigned form ---\n";
		// ShrubberyCreationForm unsignedForm("park");
		// highRank.executeForm(unsignedForm); // Should fail (form not signed)
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}