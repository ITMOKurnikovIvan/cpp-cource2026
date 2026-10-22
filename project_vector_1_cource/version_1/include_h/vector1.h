#pragma once 

class vector
{
private:
    int sz;
    double* elem;
public:
    vector(int size);
    ~vector();
    int size();
    double get(int n) const ;
    void set(int n, double v);
};