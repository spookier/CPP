#include "../incs/RobotomyRequestForm.hpp"
#include "../incs/Bureaucrat.hpp"
#include "../incs/AForm.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("NO-NAME")
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &RobotomyRequestForm)
    :AForm(RobotomyRequestForm)
{
    *this = RobotomyRequestForm;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if(this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}

	return(*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{

    check_before_executing(executor);
    
    std::cout << "BBZZZZRRR !!! *DRILLING NOISES* BZZZZRRRR !!!" << std::endl;

    int	random;
	srand(time(NULL));

 	// generate 0 or 1 -- this is a 50% probability
 	random = rand() % 2;
	
	if (random == 0)
		std::cout << this->_target << " has been successfully robotomized !" << std::endl;
	else
		std::cout << "Robotomy failed ! " << std::endl;

}

std::ostream &operator<<(std::ostream& ostream, const RobotomyRequestForm &RobotomyRequestForm)
{
	ostream << "Form " << RobotomyRequestForm.getName() << " has information of" << std::endl
		<< "Signed: " << RobotomyRequestForm.getSignedState() << std::endl
		<< "Grade required to sign: " << RobotomyRequestForm.getSignedGrade() << std::endl
		<< "Grade required to execute: " << RobotomyRequestForm.getExecGrade() << std::endl;
	return (ostream);
}