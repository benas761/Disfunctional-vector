#include <iostream>
#include "vector.h"
 
int main()
{
    Vector<char> s;
    std::cout << "Maximum size of a 'vector' is " << s.max_size() << "\n";
}