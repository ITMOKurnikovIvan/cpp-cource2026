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
    int size();
    double get(int n) const ;
    void set(int n, double v);
};