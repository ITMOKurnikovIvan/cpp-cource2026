#include "../include_h/vector1.h"
#include <iostream>

vector::vector(int size): sz(size), elem(new double[size]) 
{
    for (int i = 0; i < sz; ++i)
    {
        elem[i] = 0.0;
    }
}

vector::~vector()
{
    sz = 0;
    delete[] elem;
}
int vector::size()
{
    return sz;
}
void vector::set(int n, double v)
{
    if (n >= sz || n < 0)
    {
        std::cout << "вне диапазона" << std::endl;
        return;
    }
    elem[n] = v;
}

double vector::get(int n) const 
{
    if (n >= sz || n < 0)
    {
        std::cout << "вне диапазона" << std::endl;
        return 0.0;
    }
    return elem[n];
}