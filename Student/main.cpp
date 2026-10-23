#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "include_h/Student.h"


/*
Домашнее задание на 23.10.2026:

1) Создать класс Student с полями name_ (имя), group_ (группа), marks_ (оценки)
 и averageScore_ (средний балл).
  Класс должен иметь публичные конструктор с параметрами (имя, группа), addMark(int),
   getMarks(), getAverageScore(). При добавлении оценки посредством addMark должен 
   обновляться средний балл. Не забываем про правило пяти, если явно определили 
   какой-либо конструктор копирования/перемещения, оператор= или деструктор. 

2) Перегрузить операторы вывода (operator<<, вывод имени, группы, оценок и среднего
 балла) и сравнения на "меньше" (operator<) по среднему баллу

3) Создать вектор студентов и отсортировать его с помощью std::sort с лямбда-аргументом
 или функтором-параметром
*/

struct sort_students
{
    bool operator()(const Student& lhs, const Student& rhs) const
    {
        return lhs.getAverageScore()[0] < rhs.getAverageScore()[0];
    }
};

int main() 
{
    std::ifstream fin;
    fin.open("my_group.txt");
    if (fin.eof())
    {
        std::cout << "End Of File" << std::endl;
        return 1;
    }

    if (fin.fail())
    {
        std::cout << "Non-critical operation failure" << std::endl;
        return 1;
    }

    if (fin.bad())
    {
        std::cout << "Critical error" << std::endl;
        return 1;
    }

    if (fin.good())
    {
        std::vector<Student> my_group;
        std::string number_group;
        std::string stroka;
        //std::string 

        // std::string name;
        // std::string surname;
        // std::string patronymic;
        fin >> number_group;
        while (std::getline(fin, stroka))
        {
            if(stroka.empty()) continue;
            std::string word;
            std::string fio;
            std::istringstream iss(stroka);

            while(iss >> word)
            {
                if (word == "|")
                {
                    break;
                }
                fio += word + " ";
            }
            if(!(fio.empty()))
            {
                fio.pop_back();
            }
            my_group.push_back(Student(fio, number_group));

            std::string mark_token;
            while (std::getline(iss, mark_token, ','))
            {
                if (!mark_token.empty())
                {
                    if(!my_group.empty())
                    {
                        (my_group[my_group.size() - 1]).addMark(std::stoi(mark_token));
                
                    }
                }
            }

        }
        
        std::sort(my_group.begin(), my_group.end(), sort_students());

        //вывод списка студентов 

        for (std::size_t i = 0; i < my_group.size(); ++i)
        {
            std::cout << my_group[i] << std::endl;
        }
        return 0;
    }

    return 1;
}
