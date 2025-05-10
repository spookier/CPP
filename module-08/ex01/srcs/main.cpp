#include <iostream>
#include <vector>
#include "Span.hpp"

int main()
{
    // ------------- TEST 1 : Basic 5 numbers -----------------------------

    std::cout << "[ TEST 1 ]" << std::endl;
    Span s1(5);
    s1.addNumber(5);
    s1.addNumber(3);
    s1.addNumber(17);
    s1.addNumber(9);
    s1.addNumber(11);
    try
    {
        std::cout << "shortest span: " << s1.shortestSpan() << std::endl;
        std::cout << "longest  span: " << s1.longestSpan()  << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "error: " << e.what() << std::endl;
    }
    std::cout << std::endl;



    // ------------- TEST 2 : Zero capacity -----------------------------

    std::cout << "[ TEST 2 ]" << std::endl;
    Span s2(0);
    try
    {
        s2.addNumber(1);
    }
    catch (const std::exception& e)
    {
        std::cout << "addNumber error: " << e.what() << std::endl;
    }
    try
    {
        std::cout << "shortest span: " << s2.shortestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "longest  span: " << s2.longestSpan()  << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;



    // ------------- TEST 3 : Single element -----------------------------

    std::cout << "[ TEST 3 ]" << std::endl;
    Span s3(1);
    s3.addNumber(42);
    try
    {
        std::cout << "shortest span: " << s3.shortestSpan() << std::endl;
        std::cout << "longest  span: " << s3.longestSpan()  << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "error: " << e.what() << std::endl;
    }
    std::cout << std::endl;



    // ------------- TEST 4 : 10 000 NUMBERS -----------------------------

    std::cout << "[ TEST 4 ]" << std::endl;
    int N = 10000;
    Span s4(N);
    std::vector<int> v;
    v.reserve(N);
    for (int i = 0; i < N; ++i)
    {
        v.push_back(i);  // values 0,1,2,...,9999
    }

    s4.fill(v.begin(), v.end());

    std::cout << "shortest span: " << s4.shortestSpan() << std::endl;
    std::cout << "longest  span: " << s4.longestSpan()  << std::endl;

    return 0;

}
