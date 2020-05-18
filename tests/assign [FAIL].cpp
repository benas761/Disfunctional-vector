#include "vector.h"
#include <iostream>
 
int main()
{
    Vector<char> characters;
 
    characters.assign(5, 'a');
 
    for (char c : characters) {
        std::cout << c << ' ';
    } 
 
    characters.assign({'\n', 'C', '+', '+', '1', '1', '\n'});
 
    for (char c : characters) {
        std::cout << c;
    }
}