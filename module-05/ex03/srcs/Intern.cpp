#include "../incs/Intern.hpp"
#include "../incs/AForm.hpp"
#include "../incs/Bureaucrat.hpp"
#include "../incs/PresidentialPardonForm.hpp"
#include "../incs/RobotomyRequestForm.hpp"
#include "../incs/ShrubberyCreationForm.hpp"


Intern::Intern(): _form("NO-FORM"), _target("NO-TARGET")
{
}

Intern::Intern(std::string form, std::string target): _form(form), _target(target)
{
}

Intern::Intern(const Intern &intern)
{
	*this = intern;
}

Intern &Intern::operator=(const Intern &other)
{

	if (this != &other)
	{
		this->_form = other.get_form();
		this->_target = other.get_target();
	}

	return (*this);
}

Intern::~Intern()
{
}

const char*	Intern::NoTargetNameException::what(void) const throw()
{
	return ("No target name !");
}

const char*	Intern::NoFormNameException::what(void) const throw()
{
	return ("No form name !");
}

std::string	Intern::get_form(void) const
{
	return (_form);
}

std::string	Intern::get_target(void) const
{
	return (_target);
}

/*

i serves two purposes:

- it's used as an index to access elements in the formNames array
- it's used in the switch statement to determine which form to create 
- (if i is : 0 = shrubbery creation, 1 = robotomy request, 2 = presidential pardon)

*/

AForm*	Intern::makeForm(std::string form, std::string target)
{
	AForm		*form_ptr = NULL;

	try
	{
		if(target.empty() || target == "NO-TARGET")
			throw (NoTargetNameException());
		if(form.empty() || form == "NO-FORM")
			throw (NoFormNameException());

		static const std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

		for (int i = 0; i < 3; i++)
		{
			if (form == formNames[i])
			{
				switch(i)
				{
					case 0:
						form_ptr = new ShrubberyCreationForm(target);
						break ;

					case 1:
						form_ptr = new RobotomyRequestForm(target);
						break ;

					case 2:
						form_ptr = new PresidentialPardonForm(target);
						break ;
				}
			}
		}
	}
	catch(const std::exception &e)
	{
		std::cerr << "Intern failed to create a form due to: " << e.what() << std::endl;
	}
	return (form_ptr);
}
