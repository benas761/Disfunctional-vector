#include "vector.h"
#include <iostream>
 
void display_sizes(char const* comment,
                   const Vector<int>& nums1,
                   const Vector<int>& nums2,
                   const Vector<int>& nums3)
{
    std::cout << comment
              << " nums1: " << nums1.size() << ','
              << " nums2: " << nums2.size() << ','
              << " nums3: " << nums3.size() << '\n';
}
 
void display(char const* comment, Vector<int>& v)
{
    std::cout << comment << "{ ";
    for (int e : v) {
        std::cout << e << ' ';
    }
    std::cout << "}\n";
}
 
int main()
{
    Vector<int> nums1 {3, 1, 4, 6, 5, 9};
    Vector<int> nums2;
    Vector<int> nums3;
 
    display_sizes("Initially:\n", nums1, nums2, nums3);
 
    // copy assignment copies data from nums1 to nums2
    nums2 = nums1;
 
    display_sizes("After assigment:\n", nums1, nums2, nums3);
 
    // move assignment moves data from nums1 to nums3,
    // modifying both nums1 and nums3
    nums3 = std::move(nums1);
 
    display_sizes("After move assigment:\n", nums1, nums2, nums3);
 
    display("Now nums3 = ", nums3);
 
    // copy assignment of an initializer_list copies data to nums3
    nums3 = {1, 2, 3};
 
    display("After assignment of initializer_list \n nums3 = ", nums3);
}