// Nepavyko, kadangi nezinau kaip su std::move visu tipu reiksmes atstatyti i pradines (pvz: int/double/float/size_type = 0, string/char="" ir t.t.)
#include "vector.h"
#include <iostream>
#include <iomanip>
 
int main()
{
    Vector<std::string> numbers;
 
    numbers.push_back("abc");
    std::string s = "def";
    numbers.push_back(std::move(s));
 
    std::cout << "vector holds: ";
    for (auto&& i : numbers) std::cout << std::quoted(i) << ' ';
    std::cout << "\nMoved-from string holds " << std::quoted(s) << '\n';
}