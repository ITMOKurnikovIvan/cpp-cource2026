#include "include_h/vector2.h"
#include <iostream>

int main()
{
    int n;
    vector vec1 = {1,2.3,0.5,7,.8,9.5};
    std::cin >> n;
    if (n < 1) return 1;
    vector vec2(n);
    vector v3 = vec1;
    vector v4 {vec1};

    return 0;
}
