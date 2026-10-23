#pragma once 
#include <vector>
#include <iostream> 
#include <string>

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

class Student 
{
private:
    std::string name_;
    std::string group_;
    std::vector<int> marks_;
    double averageScore_;

    void updateaverage();
public:
    Student();
    Student(const Student&);
    Student(Student&&) noexcept;
    Student(std::string name, std::string group);

    ~Student() = default;
    // операторы 
    Student& operator=(const Student&);
    Student& operator=(Student&&) noexcept;
    
    friend std::ostream& operator<<(std::ostream&, const Student&);
    bool operator<(const Student&) const;
    bool operator>(const Student&) const;
    bool operator==(const Student&) const;
    bool operator>=(const Student&) const;
    bool operator<=(const Student&) const;
    bool operator!=(const Student&) const;

    // методы 
    void addMark(int);
    std::vector<int> getMarks() const ;
    std::vector<double> getAverageScore() const ;
//  void printAverageScore() const;

};
