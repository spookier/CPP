#include "../incs/ShrubberyCreationForm.hpp"
#include "../incs/Bureaucrat.hpp"
#include "../incs/AForm.hpp"
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("ShrubberyCreationForm", 145, 137), _target("NO-NAME")
{
}


ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ShrubberyCreationForm)
	: AForm(ShrubberyCreationForm)
{
	*this = ShrubberyCreationForm;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if(this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}

	return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{

	check_before_executing(executor);

	std::string treeAscii = 
    "              _{\\\\ _{\\{\\\\/}/}/}__\n"
    "             {/{/\\}{/{/\\}(\\}{/\\} _\n"
    "            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _\n"
    "         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n"
    "        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}\n"
    "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n"
    "      {/{/{\\{\\{\\(/}{\\{\\\\/}/}{\\}(_){\\\\/}\\}\n"
    "      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}\n"
    "     {/{/{\\{\\(/}{/{\\{\\{\\\\/})/}{\\(_)/}/}\\}\n"
    "      {\\{\\\\/}(_){\\{\\{\\\\/}/}(_){\\\\/}{\\\\/}/})/}\n"
    "       {/{\\{\\\\/}{/{\\{\\{\\\\/}/}{\\{\\\\/}/}\\}(_)\n"
    "      {/{\\{\\\\/}{/){\\{\\{\\\\/}/}{\\{\\(/}/}\\}/}\n"
    "       {/{\\{\\\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}\n"
    "         {/({/{\\{/{\\{\\\\/}(_){\\\\/}/}\\}/}(\\}\n"
    "          (_){/{\\\\/}{\\{\\\\/}/}{\\{\\)/}/}(_)\n"
    "            {/{/{\\{\\\\/}{/{\\{\\{\\(_)/}\n"
    "             {/{\\{\\{\\\\/}/}{\\{\\\\}/}\n"
    "              {){/ {\\\\/}{\\\\/} \\}\\}\n"
    "              (_)  \\.-'.-/\n"
    "          __...--- |'-.-'| --...__\n"
    "   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__\n"
    " -\"    ' .  . '    |.'-._| '  . .  '   jro\n"
    " .  '-  '    .--'  | '-.'|    .  '  . '\n"
    "          ' ..     |'-_.-|\n"
    "  .  '  .       _.-|-._ -|-._  .  '  .\n"
    "              .'   |'- .-|   '.\n"
    "  ..-'   ' .  '.   `-._.-�   .'  '  - .\n"
    "   .-' '        '-._______.-'     '  .\n"
    "        .      ~,\n"
    "    .       .   |\\   .    ' '-.\n"
    "    ___________/  \\\\____________\n"
    "   /  Why is it, when you want \\\n"
    "  |  something, it is so damn   |\n"
    "  |    much work to get it?     |\n"
    "   \\___________________________/\n";
	
	std::string	file_name = this->_target + "_shrubbery";

	std::ofstream FILE(file_name.c_str());
	if(FILE.is_open())
	{
		FILE << treeAscii;
		FILE.close();
		std:: cout << "Tree has been written to file." << std::endl;
	}
	else
	{
		std::cerr << "Unable to open file for writing." << std::endl;
	}
}


std::ostream &operator<<(std::ostream& ostream, const ShrubberyCreationForm &ShrubberyCreationForm)
{
	ostream << "Form " << ShrubberyCreationForm.getName() << " has information of" << std::endl
		<< "Signed: " << ShrubberyCreationForm.getSignedState() << std::endl
		<< "Grade required to sign: " << ShrubberyCreationForm.getSignedGrade() << std::endl
		<< "Grade required to execute: " << ShrubberyCreationForm.getExecGrade() << std::endl;
	return (ostream);
}