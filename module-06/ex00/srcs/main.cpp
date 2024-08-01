#include "../incs/ScalarConverter.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2 || std::string(argv[1]) == "")
    {
        std::cout << "Error. Need an argument." << std::endl;
        return (1);
    }
    ScalarConverter::convert(argv[1]);
    return (0);
}