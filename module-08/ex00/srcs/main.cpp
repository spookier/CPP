#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

void testVector()
{
    std::vector<int> vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);

    std::cout << "[ Testing std::vector ]" << std::endl;

    int searchVals[] = {30, 55};
    for (int i = 0; i < 2; ++i)
    {
        std::vector<int>::const_iterator it = easyfind(vec, searchVals[i]);
        if (it != vec.end())
            std::cout << "Found " << searchVals[i] << std::endl;
        else
            std::cout << "Value " << searchVals[i] << " not found." << std::endl;
    }
    std::cout << std::endl;
}

void testList()
{
    std::list<int> lst;

    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);

    std::cout << "[ Testing std::list ]" << std::endl;

    int searchVals[] = {400, 50};
    for (int i = 0; i < 2; ++i)
    {
        std::list<int>::const_iterator it = easyfind(lst, searchVals[i]);
        if (it != lst.end())
            std::cout << "Found " << searchVals[i] << std::endl;
        else
            std::cout << "Value " << searchVals[i] << " not found." << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    testVector();
    testList();
    return 0;
}
