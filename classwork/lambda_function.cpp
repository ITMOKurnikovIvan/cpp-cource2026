#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstddef>

#include <memory>

double myFunction(int a, double b)
{
    return b / a;
}

class uselsess
{
public:
    void lambdaDemonstration()
    {
        auto myLambdaThis = [this](){ return; };
        // В захвате можно передавать текущий объект с помощью ключевого слова this
        // Захватить this можно при объявлении лямбды в классе
    }
};

struct MyFunctor
{
public:
    void operator()(int increment)
    {
        counter += increment;
    }

    int getCount()
    {
        std::cout << counter << std::endl;
        return counter;
    }

private:
    int counter = 0;
};

int main()
{
    // Лямбда-функции
    int outerA = 5;
    double outerB = 3.14;
    auto myLambda = [=, &outerB](int a, double b) -> double
    {
        // = в захвате - захват всего используемого по значению без возможности изменения
        // & в захвате - захват всего используемого по ссылке
        // outerA += outerB; // <--- захват по константному значению не позволяет менять значение
        outerB += outerA; // <--- завхат по ссылке позволяет изменить значение
        return b / a + outerB;
    };
    // В захвате [] переменные захватываются по порядку перечисления
    // Кроме тех случае, когда есть явное указание захвата конкретных переменных при указанном типе всеобщего захвата 
    // В этом случае сначала захватываются явно указанные переменные, а после все остальные

    std::cout << myLambda(1, 2.71) << std::endl;
    std::cout << outerB << std::endl;

    auto myTemplateLambda = []<typename T>(T a, T b) -> bool
    {
        return a < b;
    };

    std::cout << myTemplateLambda(3.14, 2.71) << std::endl;

    std::unique_ptr<int> p = std::make_unique<int>(5);
    // Можно создавать переменные внутри списка захвата
    // Некопируемые объекты можно перемещать на месте
    auto myLambdaWithCreatedParameters = [i = 0, ptr = std::move(p)]()
    {
        int a = i;
        if (ptr)
        {
            std::cout << "ptr is not equal nullptr" << std::endl;
        }
    };

    auto myLambdaWithAutoArguments = [](auto arg){ return arg; };
    std::cout << myLambdaWithAutoArguments(50) << std::endl;
    std::cout << myLambdaWithAutoArguments("string") << std::endl;

    std::cout << "=============================================" << std::endl;

    // Функторы
    MyFunctor func;
    func(1);
    func(2);
    func(3);
    func(5);
    int count = func.getCount();

    std::cout << "=============================================" << std::endl;

    std::vector<std::string> vec{ "three", "one", "two", "another" };
    // std::sort<iterator_type, comparator_functor>() // можно передать компаратов в виде функтора в шаблонный параметр
    std::sort(vec.begin(), vec.end(), [](const std::string& lhs, const std::string& rhs){ return lhs.size() < rhs.size(); });
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << ' ';
    }
    std::cout << std::endl;

    std::sort(vec.begin(), vec.end(), [](const std::string& lhs, const std::string& rhs){ return lhs[0] < rhs[0]; });
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}