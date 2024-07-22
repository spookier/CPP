#include "../incs/AForm.hpp"
#include "../incs/Bureaucrat.hpp"

AForm::AForm() : _name("NO-NAME"), _isSigned(false), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << "Default AForm Constructor Called" << std::endl;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) 
	: _name(name), _isSigned(false),  _gradeToSign(gradeToSign), _gradeToExec(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if(gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
	: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{

}

AForm &AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		// We can only assign _isSigned, as other members are const
		this->_isSigned = other._isSigned;
	}
	
	return (*this);
}

std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSignedState() const
{
	return (this->_isSigned);
}

int AForm::getSignedGrade() const
{
	return (this->_gradeToSign);
}

int AForm::getExecGrade() const
{
	return(this->_gradeToExec);
}

void AForm::beSigned(const Bureaucrat &b)
{
	if(b.getGrade() <= this->_gradeToSign)
		this->_isSigned = true;
	else
		throw (GradeTooLowException());

}

AForm::~AForm()
{
}

std::ostream &operator<<(std::ostream &ostream, const AForm &AForm)
{
	ostream << "AForm " << AForm.getName()  << ", sign grade: " << AForm.getSignedGrade()
	<< ", execute grade: " << AForm.getExecGrade() << ", is signed: ";
	   
	   if(AForm.getSignedState() == true)
			ostream << "Yes";
	   else
			ostream << "No";

	return (ostream);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char*	AForm::NotSignedException::what(void) const throw()
{
	return ("Form is not signed");
}

void AForm::check_before_executing(Bureaucrat const &b) const
{
	if(this->getSignedGrade() < b.getGrade())
	{
		throw (GradeTooLowException());
	}
	if(this->getExecGrade() < b.getGrade())
	{
		throw (GradeTooLowException());
	}
	if(this->_isSigned == false)
	{
		throw (NotSignedException());
	}
}
