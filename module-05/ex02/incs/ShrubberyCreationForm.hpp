#ifndef SHRUBBERY_CREATION_FORM_H
# define SHRUBBERY_CREATION_FORM_H

#include "AForm.hpp"
#include <string>

class Bureaucrat;

class ShrubberyCreationForm: public AForm 
{
    private:
        std::string _target;

    public:
        ShrubberyCreationForm();  
        ShrubberyCreationForm(std::string target);  
        ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm);  
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);  
        ~ShrubberyCreationForm();  

        virtual void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream& ostream, const ShrubberyCreationForm& shrubberyCreationForm);

#endif