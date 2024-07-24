#include "../incs/Form.hpp"
#include "../incs/Bureaucrat.hpp"

Form::Form() : _name("NO-NAME"), _isSigned(false), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << "Default Form Constructor Called" << std::endl;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) 
	: _name(name), _isSigned(false),  _gradeToSign(gradeToSign), _gradeToExec(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if(gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other)
	: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{

}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		// We can only assign _isSigned, as other members are const
		this->_isSigned = other._isSigned;
	}
	
	return (*this);
}

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getSignedState() const
{
	return (this->_isSigned);
}

int Form::getSignedGrade() const
{
	return (this->_gradeToSign);
}

int Form::getExecGrade() const
{
	return(this->_gradeToExec);
}

void Form::beSigned(const Bureaucrat &b)
{
	if(b.getGrade() <= this->_gradeToSign)
		this->_isSigned = true;
	else
		throw (GradeTooLowException());

}

Form::~Form()
{
}

std::ostream &operator<<(std::ostream &ostream, const Form &form)
{
	ostream << "Form " << form.getName()  << ", sign grade: " << form.getSignedGrade()
	<< ", execute grade: " << form.getExecGrade() << ", is signed: ";
	   
	   if(form.getSignedState() == true)
			ostream << "Yes";
	   else
			ostream << "No";

	return (ostream);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}