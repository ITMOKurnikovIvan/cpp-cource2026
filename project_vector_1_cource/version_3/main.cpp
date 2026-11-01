#include "include_h/vector3.h"

int main()
{
    int n;
    vector<double> vec1 = {1, 2.3, 0.5, 7, .8, 9.5};
    std::cin >> n;
    if (n < 1) return 1;
    vector<double> vec2(n);
    vector<vector<double>> vec = {vec1, vec2};
    vector v3 = vec1;
    vector v4 {vec1};
    std::cout << vec;
    std::cout << v4 << std::endl;
    vector v5 = std::move(v4);
    std::cout << v5  << std::endl << v4  << std::endl;

    // std::sort(v5.begin(), v5.end(), rev);

    // std::cout << v5 << std::endl;

    return 0;
}