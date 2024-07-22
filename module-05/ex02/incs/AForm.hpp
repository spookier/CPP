#ifndef AForm_H
# define AForm_H

#include <string>
#include <iostream>


class Bureaucrat; // fix circular dependency without adding #include

class AForm
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeToSign;
        const int           _gradeToExec;

    public:
        AForm();
        AForm(const std::string &name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &AForm);
        AForm &operator=(const AForm &AForm);
        virtual ~AForm();


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

        class	NotSignedException: public std::exception
	    {
	        public:
		        virtual const char*	what(void) const throw();
	    };

        void check_before_executing(Bureaucrat const &b) const; // checks before "execute" function

        virtual void execute(Bureaucrat const &executor) const = 0; // turns class to abstract

        
};

std::ostream&	operator<<(std::ostream& ostream, const AForm& AForm);



#endif