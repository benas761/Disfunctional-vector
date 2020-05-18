#include "vector.h"
#include <iostream>
 
int main()
{ 
    Vector<int> nums {1, 3, 5, 7};
 
    std::cout << "nums contains " << nums.size() << " elements.\n";
}