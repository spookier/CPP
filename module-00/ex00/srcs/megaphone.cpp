// $>./megaphone "shhhhh... I think the students are asleep..."
// SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
// $>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
// DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
// $>./megaphone
// * LOU

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
            str[i] = toupper(argv[j][i]);
            i++;
        }
        std::cout << str + " ";
        j++;
    }
    std::cout << "\n";
    
    return(0);
}

