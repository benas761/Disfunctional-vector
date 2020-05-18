#include "vector.h"
#include <iostream>
 
int main()
{
    std::cout << std::boolalpha;
    Vector<int> numbers;
    std::cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';
 
    numbers.push_back(42);
    std::cout << "After adding elements, numbers.empty(): " << numbers.empty() << '\n';
}