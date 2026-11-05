#pragma once 
#include <initializer_list>
#include <algorithm>

class vector
{
private:
    int sz;
    double* elem;
public:
    vector();  
    explicit vector(int size);
    vector(std::initializer_list<double> lst);
    vector(const vector& other);
    vector(vector&& other);
    ~vector();
    vector& operator=(const vector& other);
    vector& operator=(vector&& other);
    double& operator[](int n); // operator[] не проверяет границ
    const double& operator[](int n) const; // не имеет право записывать , только чтение
    int size() const ;
    double get(int n) const ;
    void set(int n, double v);
    double* begin() const;
    double* end() const;
};