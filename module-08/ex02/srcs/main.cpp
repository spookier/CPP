#include "MutantStack.hpp"

int main()
{



    // --- TEST 1 : MutantStack
    MutantStack<int> mutant;
    mutant.push(42);
    mutant.push(1337);

    std::cout << " --- [TEST 1] --- " << std::endl;
    std::cout << "[1] Top: " << mutant.top() << std::endl;      // 1337
    mutant.pop();                                               // remove 1337
    std::cout << "[2] Top: " << mutant.top() << std::endl;      // 42

    std::cout << "Size: " << mutant.size() << std::endl;        // size after removing 1337
    std::cout << "-------------------" << std::endl << std::endl;



    // --- TEST 2 : Just add more elements and use the iterators to print them
    std::cout << " --- [TEST 2] --- " << std::endl;
    mutant.push(10);
    mutant.push(20);
    mutant.push(444);
    mutant.push(0);

    std::cout << "Contents:" << std::endl;
    for (MutantStack<int>::iterator it = mutant.begin(); it != mutant.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    std::cout << "-------------------" << std::endl << std::endl;



    // --- TEST 3 : Use std::list
    std::cout << " --- [TEST 3] --- " << std::endl;
    std::list<int> list;
    list.push_back(5);
    list.push_back(17);
    
    std::cout << "[1] Last Element: " << list.back() << std::endl;
    list.pop_back();                                                // remove 17
    std::cout << "[2] Last Element: " << list.back() << std::endl;  
    std::cout << "Size: " << list.size() << std::endl;
    std::cout << "-------------------" << std::endl << std::endl;


    // --- TEST 4 : Just add more elements and use the iterators to print them
    std::cout << " --- [TEST 4] --- " << std::endl;
    list.push_back(10);
    list.push_back(20);
    list.push_back(444);
    list.push_back(0);

    std::cout << "Contents:" << std::endl;
    for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    std::cout << "-------------------" << std::endl << std::endl;

    return 0;
}
