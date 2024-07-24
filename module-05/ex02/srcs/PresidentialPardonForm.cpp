#include "../incs/PresidentialPardonForm.hpp"
#include "../incs/Bureaucrat.hpp"
#include "../incs/AForm.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), _target("NO-NAME")
{
	
}


PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &PresidentialPardonForm)
	: AForm(PresidentialPardonForm)
{
	*this = PresidentialPardonForm;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}

	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	check_before_executing(executor);

	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox !" << std::endl;
}

std::ostream &operator<<(std::ostream& ostream, const PresidentialPardonForm &PresidentialPardonForm)
{
	ostream << "Form " << PresidentialPardonForm.getName() << " has information of" << std::endl
		<< "Signed: " << PresidentialPardonForm.getSignedState() << std::endl
		<< "Grade required to sign: " << PresidentialPardonForm.getSignedGrade() << std::endl
		<< "Grade required to execute: " << PresidentialPardonForm.getExecGrade() << std::endl;
	return (ostream);
}