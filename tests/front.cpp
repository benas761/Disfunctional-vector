#include "vector.h"
#include <iostream>
 
int main()
{
    Vector<char> letters {'o', 'm', 'g', 'w', 't', 'f'};
 
    if (!letters.empty()) {
        std::cout << "The first character is: " << letters.front() << '\n';
    }  
}