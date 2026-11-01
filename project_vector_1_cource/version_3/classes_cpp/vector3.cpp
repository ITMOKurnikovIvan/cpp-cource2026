#include "../include_h/vector3.h"

template<typename T, typename A>
vector<T, A>::vector(): sz(1), elem(nullptr) {} 

template<typename T, typename A>
vector::vector(int size): sz(size), elem(new double[size]) 
{
    for (int i = 0; i < sz; ++i)
    {
        elem[i] = 0.0;
    }
}
template<typename T, typename A>
vector<T,A>::vector(std::initializer_list<double> lst): sz(lst.size()), elem(new double[lst.size()])
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

template<typename T, typename A>
void vector<T,A>::reserve(int newalloc)
{
    if (newalloc <= this->space) return; // безопасность 

    vector_base<T,A> b(this->alloc, newalloc);        

    uninitialized_copy(b.elem, &b.elem[this->sz], this->elem); 

    for (int i = 0; i < this->sz; ++i)
        this->alloc.destroy(&this->elem[i]);         

    swap<vector_base<T,A>>(*this, b);                
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
