#pragma once 


class vector
{
private:
    // vector* next;
    // vector* pred;
    struct Link;
    Link* elem = nullptr;
    int size_;
public:
    vector();
    vector(int size);
    vector(const vector&);
    vector(vector&&) noexcept;
    vector& operator=(const vector&);
    vector& operator=(vector&&) noexcept;
    ~vector();

    int size() const;
    double get(int n) const;
    void set(int n, double v);
    void append(double number);
    int find(double v) const;
    void erase(int number);
    void erase(double v);
};