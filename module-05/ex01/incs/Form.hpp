#ifndef FORM_H
# define FORM_H

#include <string>
#include <iostream>


class Bureaucrat; // fix circular dependency without adding #include

class Form
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeToSign;
        const int           _gradeToExec;

    public:
        Form();
        Form(const std::string &name, int gradeToSign, int gradeToExecute);
        Form(const Form &form);
        Form &operator=(const Form &form);
        ~Form();


        std::string getName() const;
        bool        getSignedState() const;
        int         getSignedGrade() const;
        int         getExecGrade() const;

        void		beSigned(const Bureaucrat &b);


        class	GradeTooHighException: public std::exception
        {
            public:
                virtual const char*	what(void) const throw();
        };

        class	GradeTooLowException: public std::exception
        {
            public:
                virtual const char*	what(void) const throw();
        };
};

std::ostream&	operator<<(std::ostream& ostream, const Form& form);








#endif