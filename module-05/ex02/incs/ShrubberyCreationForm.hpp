#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include <string>

class Bureaucrat;

class ShrubberyCreationForm: public AForm 
{
public:
    ShrubberyCreationForm();  
    ShrubberyCreationForm(std::string target);  
    ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm);  
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);  
    ~ShrubberyCreationForm();  

    virtual void execute(Bureaucrat const &executor) const;

private:
    std::string _target;
};

std::ostream& operator<<(std::ostream& ostream, const ShrubberyCreationForm& shrubberyCreationForm);

#endif