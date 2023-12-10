#include <iostream>
#include <string>

int main(int argc, char **argv)
{

    std::string str;
    int i;
    int j;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return(0);
    }

    i = 0;
    j = 1;
    while (j < argc)
    {
        str = argv[j];
        i = 0;
        while (argv[j][i])
        {
            str[i] = std::toupper(argv[j][i]);
            i++;
        }
        std::cout << str + " ";
        j++;
    }
    std::cout << "\n";
    
    return(0);
}

