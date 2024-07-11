#include "../incs/Bureaucrat.hpp"
#include "../incs/Form.hpp"

int main()
{
    std::cout << "----- Testing Bureaucrat -----" << std::endl;
    try
    {
        Bureaucrat high("Alex", 1);
        std::cout << high << std::endl;
        
        Bureaucrat low("Bob", 150);
        std::cout << low << std::endl;
        
        high.decrementGrade();
        std::cout << "After decrement: " << high << std::endl;
        
        low.incrementGrade();
        std::cout << "After increment: " << low << std::endl;
        
        // This should throw an exception
        Bureaucrat invalid("Invalid", 200);
    } catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // std::cout << "\n----- Testing Form -----" << std::endl;

    // try {
    //     Form defaultForm;
    //     std::cout << "Default form: " << defaultForm << std::endl;
        
    //     Form customForm("Custom Form", 50, 25);
    //     std::cout << "Custom form: " << customForm << std::endl;
        
    //     Form copyForm(customForm);
    //     std::cout << "Copy of custom form: " << copyForm << std::endl;
        
    //     // Testing assignment operator
    //     defaultForm = customForm;
    //     std::cout << "Default form after assignment: " << defaultForm << std::endl;
        
    //     // This should throw an exception
    //     Form invalidForm("Invalid Form", 0, 151);
    // } catch (std::exception& e) {
    //     std::cout << "Exception caught: " << e.what() << std::endl;
    // }

    // std::cout << "\n--- Testing Form Signing ---" << std::endl;
    // try {
    //     Bureaucrat ceo("CEO", 1);
    //     Bureaucrat intern("Intern", 150);
        
    //     Form easyForm("Easy Form", 100, 100);
    //     Form hardForm("Hard Form", 1, 1);
        
    //     std::cout << "---> Before signing:" << std::endl;
    //     std::cout << easyForm << std::endl;
    //     std::cout << hardForm << std::endl;
        
    //     ceo.signForm(easyForm);
    //     ceo.signForm(hardForm);
        
    //     intern.signForm(easyForm);
    //     intern.signForm(hardForm);
        
    //     std::cout << "---> After signing attempts:" << std::endl;
    //     std::cout << easyForm << std::endl;
    //     std::cout << hardForm << std::endl;
    // } catch (std::exception& e)
    // {
    //     std::cout << "Exception caught: " << e.what() << std::endl;
    // }

    // return 0;
}