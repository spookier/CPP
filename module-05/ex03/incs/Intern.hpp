#ifndef INTERN_H
# define INTERN_H

#include <AForm.hpp>
#include <string>

class	Intern
{
	public:
		Intern();
		Intern(std::string form, std::string target);
		Intern(const Intern &intern);
		Intern& operator=(const Intern &intern);
		~Intern();

		class	NoTargetNameException: public std::exception
		{
			public:
				virtual const char*	what(void) const throw();
		};

		class	NoFormNameException: public std::exception
		{
			public:
				virtual const char*	what(void) const throw();
		};

		std::string	get_form(void) const;
		std::string	get_target(void) const;


		AForm*		makeForm(std::string form, std::string target);

	private:
		std::string	_form;
		std::string	_target;
};


#endif