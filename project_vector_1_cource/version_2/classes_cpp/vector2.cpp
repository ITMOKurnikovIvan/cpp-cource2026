#include "../include_h/vector2.h"

vector::vector(): sz(0), elem(nullptr) {} 

vector::vector(int size): sz(size), elem(new double[size]) 
{
    for (int i = 0; i < sz; ++i)
    {
        elem[i] = 0.0;
    }
}

vector::vector(std::initializer_list<double> lst): sz(lst.size()), elem(new double[lst.size()])
{
    std::copy(lst.begin(), lst.end(), elem);
}

vector::vector(const vector& other): sz(other.sz), elem(new double[other.sz])
{
    std::copy(other.elem, other.elem + other.sz, elem);
}

vector::vector( vector&& other ): sz(other.sz), elem(other.elem)
{
    other.elem = nullptr;
    other.sz = 0;
}

vector::~vector()
{
    sz = 0;
    delete[] elem;
}


vector& vector::operator=(const vector& other)
{
    double* p = new double[other.sz];
    std::copy(other.elem, other.elem + other.sz, p);

    delete[] elem;
    elem = p;
    sz = other.sz;

    return *this;
}

vector& vector::operator=(vector&& other)
{
    if (this != &other)
    {
        delete[] elem;
        sz = other.sz;
        elem = other.elem;
        other.elem = nullptr;
        other.sz = 0;
    }
    return *this;
}

double& vector::operator[](int n)
{
    return elem[n];
}

const double& vector::operator[](int n) const 
{
    return elem[n];
}

int vector::size() const 
{
    return sz;
}
void vector::set(int n, double v)
{
    elem[n] = v;
}

double vector::get(int n) const 
{
    return elem[n];
}

double* vector::begin() const
{
    return elem;    
}

double* vector::end() const
{
    return elem + size();    
}