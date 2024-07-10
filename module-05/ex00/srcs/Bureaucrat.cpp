#include "../incs/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("NO-NAME"), _grade(150)
{
    std::cout << "Default Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();

    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat)
{
	*this = bureaucrat;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
	if (this == &bureaucrat)
		return (*this);

	// We can't assign to name because it's const
	this->_grade = bureaucrat.getGrade();

	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too HIGH!");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too LOW!");
}

std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade()
{
		if (_grade - 1 < 1)
			throw (GradeTooHighException());

    this->_grade--;
}

void	Bureaucrat::decrementGrade()
{
		if (_grade + 1 > 150)
			throw (GradeTooLowException());
            
    this->_grade++;
}

std::ostream    &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat)
{
	ostream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (ostream);
}