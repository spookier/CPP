#include "../incs/iter.hpp"


int main()
{
    // Test with INT ARRAY
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLength = 5;

    // Print original
    std::cout << "Original intArray: ";
    iter(intArray, intLength, printElement<int>);

    // Increment it then print again
    std::cout << "\nAfter increment: ";
    iter(intArray, intLength, increment<int>);
    iter(intArray, intLength, printElement<int>);
    std::cout << "\n";


    // // Test with STRING ARRAY
    // std::string strArray[] = {"Hello", "World", "Cats", "Dogs"};
    // size_t strLength = 4;

    // std::cout << "Original strArray: ";
    // iter(strArray, strLength, printElement<std::string>);
    // std::cout << "\n";

    return 0;
}