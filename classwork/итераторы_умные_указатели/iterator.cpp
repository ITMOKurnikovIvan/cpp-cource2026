#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <list>

int main()
{
    std::vector<int> vec{0,1,2,3,4,5,12,1,0,5,3};
    // проходимся по диапозону [begin , end ) end указывает на не принадлежащий вектору 
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << ' '; 
    }
    std::cout << std::endl;

    for (auto elem : vec)
    {
        ;
    }

    // категории итераторов 
    // 1. output только для записи(единоразовая запись в потоках вывода например ) элементов // опеределена операция ++ смещение по элементу 
    // 2. input только для чтения( многократное )  // определены операции ++ == != 
    // 3. forward многопроходные чтения и записи одноврменно || односвязный список 
    // 4. bidirectional  все операции которые выше  `--` примр объекта -- двусвязный список
    // 5. random access все что выше + - [] < > || пример объекта -- vector 

    std::sort(vec.begin(), vec.end());
    for (auto elem : vec)
    {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;

    std::list<int> list1{3,1,2,6,0};

    list1.sort();
    for (auto elem : vec)
    {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;

    //-----------------

    auto begIt = vec.begin();
    std::advance(begIt, -3);
    std::cout << *begIt << std::endl;
    std::advance(begIt, -3);
    std::cout << *begIt << std::endl;
    std::advance(begIt, -3);
    std::cout << *begIt << std::endl;        

    auto distance = std::distance(vec.begin(), begIt);
    std::cout << distance << std::endl;

    auto iter1 = std::next(vec.begin(), 2);
    std::cout << *iter1 << std::endl;
    auto iter2 = std::prev(vec.end(), 2);
    std::cout  << *iter2 << std::endl;

    // reverse  iteration 

    for (auto revIt = vec.rbegin(); revIt != vec.rend(); ++revIt)
    {
        std::cout << *revIt << ' ';
    }
    std::cout << std::endl;

    // инвалидация итераторов 

    auto iter3 = vec.begin();
    vec.push_back(5);
    std::cout << *iter3 << std::endl;
    iter3 = vec.begin();
    std::cout << *iter3 << std::endl;
int summ = 0;
for ( auto iti = vec.begin() + 1; iti != vec.end() && iti != vec.end() - 1; iti += 2)
{
    summ += *iti; 
}
std::cout << summ << std::endl;

}
