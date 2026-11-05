#include "include_h/vector2.h"
#include <iostream>
#include <algorithm>

std::ostream& operator<<(std::ostream& os, const vector & a)
{
    os << "{ ";
    for (int i = 0; i < a.size(); ++i)
    {
        os << a[i] << " ";
    }
    return os << "}";
}

bool rev(double lhs, double rhs)
{
    return lhs > rhs;
}

int main()
{
    int n;
    vector vec1 = {1, 2.3, 0.5, 7, .8, 9.5};
    std::cin >> n;
    if (n < 1) return 1;
    vector vec2(n);
    vector v3 = vec1;
    vector v4 {vec1};

    std::cout << v4 << std::endl;
    vector v5 = std::move(v4);
    std::cout << v5  << std::endl << v4  << std::endl;

    std::sort(v5.begin(), v5.end(), rev);

    std::cout << v5 << std::endl;
    return 0;
}
