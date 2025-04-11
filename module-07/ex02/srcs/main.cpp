#include "../incs/Array.hpp"
#include <iostream>

int main()
{
    // === Test 1: Trying to access an out of bounds array ===
    try {
        std::cout << "Test 1 " << std::endl;

        Array<char> charArray(10);
        char currentChar = 'a';

        std::cout << "Filling and printing charArray:\n";
        for (int i = 0; i < 10; i++)
        {
            charArray[i] = currentChar++;
            std::cout << "charArray[" << i << "] = " << charArray[i] << std::endl;
        }

        // Intentionally accessing out-of-bounds element to trigger exception
        std::cout << "--> Accessing out-of-bounds index 20\n";
        charArray[20];
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << "\n" << std::endl;
    }

    // === Test 2: Using copy constructor and int array ===
    try {
        std::cout << "Test 2 " << std::endl;

        const int size = 10;
        Array<int> intArray(size);

        std::cout << "Filling intArray:\n";
        for (int i = 0; i < size; i++)
        {
            intArray[i] = i;
            std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
        }

        std::cout << "\n--> Copying intArray into newArr:\n";
        Array<int> newArr(intArray);
        for (int i = 0; i < size; i++)
        {
            std::cout << "newArr[" << i << "] = " << newArr[i] << std::endl;
        }

    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << "\n" << std::endl;
    }

    // === Test 3: Trying to access empty array ===
    try {
        std::cout << std::endl << "Test 3 " << std::endl;
        Array<int> emptyArray;

        std::cout << "--> Trying to access index 0 of the empty array\n";

        emptyArray[0] = 42;

        std::cout << "emptyArray[0] = " << emptyArray[0] << std::endl;

    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << "\n" << std::endl;
    }

    return 0;
}
