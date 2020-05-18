#include "vector.h"
#include <iostream>
 
int main()
{
    Vector<char> letters {'a', 'b', 'c', 'd', 'e', 'f'};
    if (!letters.empty()) {
        std::cout << "The last character is: " << letters.back() << '\n';
    }  
}