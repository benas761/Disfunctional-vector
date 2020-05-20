// Problema siunciant masyvo pointer'ius kaip iteratorius, kadangi std::distance su jais neveikia. Nezinau ka be jo galiu naudoti.
#include <iostream>
#include "vector.h"
 
void print_vec(Vector<int>& vec)
{
    for (auto x: vec) {
         std::cout << ' ' << x;
    }
    std::cout << '\n';
}
 
int main ()
{
    Vector<int> vec(3,100);
    print_vec(vec);
 
    auto it = vec.begin();
    it = vec.insert(it, 200);
    print_vec(vec);
 
    vec.insert(it,2,300);
    print_vec(vec);
 
    // "it" no longer valid, get a new one:
    it = vec.begin();
 
    std::vector<int> vec2(2,400);
    vec.insert(it+2, vec2.begin(), vec2.end());
    print_vec(vec);
 
    int arr[] = { 501,502,503 };
    vec.insert(vec.begin(), arr, arr+3);
    print_vec(vec);
}