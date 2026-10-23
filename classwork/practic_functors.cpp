#include <iostream> 
/*
Оставшаяся задача:
Реализовать функтор Sum, хранящий внутри переменную sum_.
 При вызове оператора круглых скобок sum_ должен обновляться посредством добавления аргумента. 
С помощью метода getSum() проверить реализацию
*/

struct Sum
{
private:
    int sum_;
public:
    Sum (): sum_(0){};
    Sum (int n): sum_(n){};
    void operator()(int num){ sum_ += num; };
    int getSum()
    {
        return sum_;
    }
};
int main()
{
    Sum a;
    for (size_t i = 0; i < 17 ; ++i)
    {
        a(i);
        std::cout << a.getSum() << std::endl;
    }
    std::cout << std::endl << a.getSum() << std::endl;
}