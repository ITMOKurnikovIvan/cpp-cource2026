#pragma once 

#include <string>

using std::string;

class Shape{
public:
    // конструкторы 
    Shape();
    Shape(const Shape& other);
    Shape(Shape&& other) noexcept;
    Shape(string other); // неявное преобразование из string

    // деструкторы
    ~Shape();

    // операторы 
    Shape& operator=(const Shape& other);
    Shape& operator=(Shape&& other) noexcept;
        // сравнения  
        // невозможно обязать все наследующие классы создать оператор, так как обязателен параметр
    bool operator>(const Shape& other) const;
    bool operator<(const Shape& other) const;
    bool operator==(const Shape& other) const;
    bool operator!=(const Shape& other) const;
    bool operator^(const Shape& other) const;
        // вывода 
    friend std::ostream& operator<<(std::ostream& os, const Shape& this_);

    // методы 
    string getName() const;
    virtual double area() const =0;
    virtual double perimetr()const =0;




protected:
    string name;
       // важные функции для сравнения 
    // virtual bool equal_ravenstvo_area(const Shape& other) const;
    // virtual bool equal_ravenstvo_perimetr(const Shape& other) const;
    // virtual bool equal_bolse_area(const Shape& other) const ;
    
};

