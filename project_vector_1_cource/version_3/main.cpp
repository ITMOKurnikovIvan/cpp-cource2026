    #include "include_h/vector3.h"
    template<typename T>
    struct functor
    {
    public:
        bool operator()(const T& lhs, const T& rhs) const
        {
            return abs(lhs) > abs(rhs) ;
        }
    };

    int main()
    {
        int n;
        vector<double> vec1 = {1, 2.3, 0.5, 7, .8, 9.5};
        std::cin >> n;
        if (n < 1) return 1;
        vector<double> vec2(n);
        for (int i = 0; i < n; ++i)
        {
            vec2[i] = 1.12 * i - 4;
        }
        vector<vector<double>> vec = {vec1, vec2};
        vector v3 = vec1;
        vector v4 {vec1};
        std::cout << vec << std::endl;
        std::cout << v4 << std::endl;
        vector v5 = std::move(v4);
        std::cout << v5  << std::endl << v4  << std::endl;
        std::sort(vec2.begin(), vec2.end(), functor<double>());
        std::sort(vec.begin(), vec.end(), [](const vector<double>& lhs, const vector<double>& rhs){return lhs[0] > rhs[0];});

        std::cout << vec2 << std::endl;
        std::cout << vec << std::endl;
        // std::sort(v5.begin(), v5.end(), rev);

        // std::cout << v5 << std::endl;

        return 0;
    }