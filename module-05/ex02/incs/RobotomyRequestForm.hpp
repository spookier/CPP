#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm: public AForm 
{
public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &RobotomyRequestForm);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
    ~RobotomyRequestForm();

    virtual void execute(Bureaucrat const &executor) const;

private:
    std::string _target;
};

std::ostream& operator << (std::ostream& ostream, const RobotomyRequestForm &RobotomyRequestForm);

#endif