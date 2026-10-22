#include "include_h/vector1.h"
#include <iostream>


int main(void)
{
    int size = 0;
    std::cin >> size;
    vector v(size);
    for (int i = 0; i < size; ++i)
    {
        v.set(i, 1.2 * i);
        std::cout << "v[" << i << "] = " << v.get(i) << std::endl;
    } 
}