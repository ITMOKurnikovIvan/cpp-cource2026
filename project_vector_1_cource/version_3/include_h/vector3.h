#pragma once 
#include <memory>
#include <initializer_list>
#include <algorithm>
#include <utility>
#include <stdexcept>
#include <memory>
#include <iostream>
#include <concepts>


template<typename T, typename A> // A --> аллокатор 
struct vector_base {
    A alloc;    
    T* elem;    
    int sz;     
    int space;  
    
    vector_base(const A& a, int n):alloc{a}, elem{n > 0 ? alloc.allocate(n) : nullptr}, sz{n}, space{n}{}
    
    vector_base(vector_base&& other) noexcept
    : alloc(std::move(other.alloc))
    , elem(other.elem)
    , sz(other.sz)
    , space(other.space)
    {
        other.elem = nullptr;
        other.sz = 0;
        other.space = 0;
    }

    vector_base& operator=(vector_base&& other) noexcept
    {
        if (this != &other)
        {
            alloc.deallocate(elem, space); // std::allocator_traits<A>::deallocate(alloc, elem, space); если хочется чтобы автоматически подставлял реализации по умлочанию 
            alloc = std::move(other.alloc);
            elem = other.elem;
            sz = other.sz;
            space = other.space;
            other.space = 0;
            other.sz = 0;
            other.elem = nullptr;
        }
        return *this;
    }
    ~vector_base()
    {
        alloc.deallocate(elem, space); // освобождает память, не вызывая реальные деструкторы , освобождает сырую память ::operator delete()
    }
    // Копирование запрещено --> иначе двойное освобождение
    // vector_base не знает, как копировать элементы
    vector_base(const vector_base&) = delete; 
    vector_base& operator=(const vector_base&) = delete;
};

template<typename T>
concept stream = requires(std::ostream& os, T a)
{
    {os << a};
};

template<typename T, typename A = std::allocator<T>>
class vector: private vector_base<T, A>
{
    private:
    using base = vector_base<T, A>;
    using traits = std::allocator_traits<A>; // генерация кода который забыт в аллокаторе А 
public:
    vector(const A& alloc = A()): base(alloc, 0) {}  
    explicit vector(int size, const T& default_ = T(), const A& alloc= A()): base(alloc, 0)// запрещает неявное преобразование вектора из int 
    {
        if(size > 0)
        {
            reserve(size);
            std::uninitialized_fill_n(this->elem, size, default_);
            this->sz = size;
        }
    }

    vector(std::initializer_list<T> lst, const A& alloc= A()): base(alloc, 0)
    {
        reserve(lst.size());
        std::uninitialized_copy(lst.begin(), lst.end(), this->elem);
        this->sz = lst.size();
    }

    vector(const vector& other): base(other.alloc, 0)
    {
        reserve(other.size());
        std::uninitialized_copy(other.elem, other.elem + other.sz, this->elem);
        this->sz = other.size();
    }

    vector(vector&& other) noexcept: base(std::move(other)){}

    ~vector()
    {
        for (int i = 0; i < this->sz; ++i)
        {
            traits::destroy(this->alloc, &(this->elem[i])); // саму паямять не трогаем , существует vector base 
        }
    }

    vector& operator=(const vector& other)
    {
        vector temp(other);

            for (int i = 0; i < this->sz; ++i)
            {
                traits::destroy(this->alloc, &(this->elem[i])); // саму паямять не трогаем , существует vector base 
            }

        static_cast<base&>(*this) = std::move(static_cast<base&>(temp));

        return *this;
    }

    vector& operator=(vector&& other)
    {
        if (this != &other)
        {
            for (int i = 0; i < this->sz; ++i)
            {
                traits::destroy(this->alloc, &(this->elem[i])); // саму паямять не трогаем , существует vector base 
            }
            static_cast<base&>(*this) = std::move(static_cast<base&>(other));
        }
        return *this;
    }
    
    T& operator[](int n) // operator[] не проверяет границ     
    {
        return this->elem[n];
    }
    
    const T& operator[](int n) const // не имеет право записывать , только чтение
    {
        return this->elem[n];
    }
    
    void reserve(int newalloc)
    {
        if(newalloc < 0) throw std::invalid_argument("длина положительна должна быть");
        else{
        if (newalloc <= this->space) return; // безопасность 
        
        vector_base<T,A> b(this->alloc, newalloc);        
        
        // std::uninitialized_copy(this->elem, &(this->elem[this->sz]), b.elem); 
        for(int i = 0; i < this->sz; ++i)
        {
            traits::construct(this->alloc, &(b.elem[i]), this->elem[i]);
        }

        for (int i = 0; i < this->sz; ++i)
        {
            traits::destroy(this->alloc,&this->elem[i]);         
        }
        b.sz = this->sz;
        static_cast<base&>(*this) = std::move(b); 
        }       
    }
    
    void shrink_to_fit()
    {
        if (this->space == size()) return;
        vector_base<T,A> b(this->alloc, this->size());        
        
        std::uninitialized_copy(this->elem, &(this->elem[this->sz]), b.elem); 
        
        for (int i = 0; i < this->sz; ++i)
        {
            traits::destroy(&this->elem[i]);         
        }
        static_cast<base&>(*this) = std::move(b);
    }
    
    void push_back(const T& one_elem)
    {
        if (this->sz == this->space)
        {
            reserve(this->sz == 0 ? 8 : 2 * size());
        }
        traits::construct(this->alloc, &(this->elem[this->sz]), one_elem);
        ++(this->sz);
    }
    
    
    void resize(int newsize, T default_ = T()) //при resize вниз мы уничтожаем объекты, но не освобождаем память работает с объектами , а не с памятью
    {
        if(newsize < 0) throw std::invalid_argument("длина положительна должна быть");
        else{
        reserve(newsize);
        for (int i = newsize; i < this->sz; ++i)
        {
            traits::destroy(this->alloc, &(this->elem[i]));
        }
        for (int i = this->sz; i < newsize; ++i)
        {
            traits::construct(this->alloc, &(this->elem[i]), default_);
        }
        this->sz = newsize;
        }
    }
    
    void clear()
    {
        for (int i = 0; i < this->sz; ++i)
        {
            traits::destroy(this->alloc, &(this->elem[i]));
        }
        this->sz = 0;
    }

    void pop_back()
    {
        if (this->sz != 0)
        {
            traits::destroy(this->alloc, &(this->elem[this->sz - 1]));
            --(this->sz);
        }
    }
    T& at(int index)
    {
        if (index < 0 || index >= size())
        {
            throw std::invalid_argument("индекс вне диапазона допустимых значений");
        }
        else
        {
            return this->elem[index];
        }
    }
    
    const T& at(int index) const 
    {
        if (index < 0 || index >= size())
        {
            throw std::invalid_argument("индекс вне диапазона допустимых значений");
        }
        else
        {
            return this->elem[index];
        }
    }
    
    friend void swap(vector& fir, vector& sec) noexcept
    {
        vector temp = std::move(fir);
        fir = std::move(sec);
        sec = std::move(temp);
    }

    T* begin() 
    {
        return this->elem;
    }
    T* end()
    {
        return this->elem + size();
    }
    int capacity() const 
    {
        return this->space;
    }
    int size() const
    {
        return this->sz;
    }
    // double get(int n) const 
    // {
        // return elem[n];
        // }
        void set(int n, T v)
        {
            this->elem[n] = v;
        }
        

    friend std::ostream& operator<<(std::ostream& os, const vector<T, A>& el) 
    {
        if constexpr (!stream<T>)
        {
            throw std::invalid_argument("у типа данных нет оператора вывода");
        }

        else{
            os << "{";
            for (int i = 0; i < el.size(); ++i)
            {
                os << el[i] << " ";
            }
            os << "}";
            return os;
        }
    }
};