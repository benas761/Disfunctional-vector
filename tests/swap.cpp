#include "vector.h"
#include <iostream>
 
void printVector(Vector<int>& vec)
{
    for (int a : vec)
    {
        std::cout << a << " ";
    }
}
 
int main()
{
    Vector<int> v1{1, 2, 3};
    Vector<int> v2{7, 8, 9};
 
    std::cout << "v1: ";
    printVector(v1);
 
    std::cout << "\nv2: ";
    printVector(v2);
 
    std::cout << "\n-- SWAP\n";
    v2.swap(v1);
 
    std::cout << "v1: ";
    printVector(v1);
 
    std::cout << "\nv2: ";
    printVector(v2);
}