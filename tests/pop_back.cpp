#include "vector.h"
#include <iostream>
 
template<typename T>
void print(T & xs)
{
    std::cout << "[ ";
    for(auto & x : xs) {
        std::cout << x << ' ';
    }
    std::cout << "]\n";
}
 
int main()
{
    Vector<int> numbers;
 
    print(numbers); 
 
    numbers.push_back(5);
    numbers.push_back(3);
    numbers.push_back(4);
 
    print(numbers); 
 
    numbers.pop_back();
 
    print(numbers); 
}