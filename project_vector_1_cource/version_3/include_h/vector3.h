#pragma once 
#include <cstdint>
#include <memory>
#include <initializer_list>
#include <algorithm>
#include <new>
#include <ostream>
#include <type_traits>
#include <utility>
#include <stdexcept>
#include <memory>
#include <iostream>
// #include <concepts>


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

template<typename T, typename = void>
struct has_stream: std::false_type{};

template <typename T>
struct has_stream<T, std::void_t<decltype(std::declval<std::ostream&>() << std::declval<T>())>> 
    : std::true_type {};

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
        if constexpr (!has_stream<T>::value)
        {
            os << "у типа данных нет оператора вывода";
            // throw std::invalid_argument("у типа данных нет оператора вывода");
        }

        else{
            os << "{";
            for (int i = 0; i < el.size(); ++i)
            {
                os << el[i] << " ";
            }
            os << "}";
        }
        return os;
    }
};

template<typename A>
class vector<bool, A>
{
private:
    char* arr;
    int cp;
    int sz;
    struct BitReference
    {
        char* cell;
        uint8_t index;
        BitReference(char* cell, uint8_t index) noexcept: cell(cell), index(index){}
        BitReference& operator=(bool b){
            if(b)
            {
                *cell |= (1 << index);
            } else {
                *cell &= ~(1 << index);
            }
            return *this;
        }
        operator bool(){
            return (*cell & (1 << index)) != 0;
        }
    };

    struct Data
    {
        int size;
        char* newarr;
        Data(int size): size(size), newarr(nullptr){
            newarr = static_cast<char*>(::operator new[](size));
        }
        char& operator[](int index)
        {
            return newarr[index];
        }
        ~Data(){
            ::operator delete[](newarr);
        }
    };
public:
    vector(): arr(nullptr), cp(0), sz(0){}
    explicit vector(int size, bool default_ = false): arr(nullptr), cp(0), sz(size) 
    {
        if(sz > 0)
        {
            int bits_needed = (sz + 7) / 8;
            arr = static_cast<char*>(::operator new[](bits_needed));
            char default_value = (default_ ? 0xFF : 0x00);

            for(int i = 0; i < bits_needed; ++i)
            {
                arr[i] = default_value;
            }
        }
    }
    vector(std::initializer_list<bool> lst): sz(lst.size()), cp(0), arr(nullptr){
        int bits_needed = (sz + 7) / 8;
        cp = bits_needed * 8;
        arr = static_cast<char*>(::operator new[](bits_needed));
        for(int i = 0; i < sz; ++i)
        {
            arr[i] = 0;
        }
        int i = 0;
        for(bool value : lst)
        {
                                    // if(value)
                                    // {
                                    //     arr[i / 8] |= (1 << (i % 8));
                                    // }else{
                                    //     arr[i / 8] &= ~(1 << (i % 8));
                                    // }
            (*this)[i] = value;
            ++i;
        }
        
    }

    vector(const vector<bool>& other): sz(other.sz), cp(other.cp), arr(nullptr){
        if(other.arr != nullptr && other.cp > 0)
        {
            arr = static_cast<char*>(::operator new[]((cp + 7) / 8));
            std::copy(other.arr, other.arr + (other.cp + 7) / 8, arr);
        }
    }

    vector(vector<bool>&& other) noexcept: sz(other.sz), cp(other.cp), arr(other.arr){
        other.arr = nullptr;
        other.sz = 0;
        other.cp = 0;
    }

    vector<bool>& operator=(const vector<bool>& other){
        ::operator delete[](arr);
        sz = other.sz;
        cp = other.cp;
        int byte_needed = (cp + 7) / 8;
        arr = static_cast<char*>(::operator new[](byte_needed));
        std::copy(other.arr, other.arr + byte_needed, arr);

        return *this;
    }

    vector<bool> operator=(vector<bool>&& other) noexcept{
        ::operator delete[](arr);
        sz = other.sz;
        cp = other.cp;
        arr = other.arr;
        
        return *this;
    }

    

    ~vector(){
        ::operator delete[](arr);
    }
    BitReference& operator[](int index){
        return BitReference{arr + index / 8, index % 8};
    }
    bool operator[](int index) const noexcept {
        return bool(BitReference{arr + index / 8, index % 8}) ;
    }

    void reserve(int newalloc)
    {
        if(cp >= newalloc) return;
        else{
            int byte_old = (cp + 7) / 8;
            Data newarr{(newalloc + 7) / 8};
            // char* newarr = static_cast<char*>(::operator new[]((newalloc + 7) / 8));
            // std::copy(arr, arr + byte_needed, newarr)
            for(int i = 0; i < byte_old; ++i)
            {
                newarr[i] = arr[i];
            }
            ::operator delete[](arr);
            arr = newarr.newarr;
            newarr.newarr = nullptr;
            cp = ((newalloc + 7) / 8) * 8;
            
        }
    }
    void shrink_to_fit()
    {
        if(cp == ((sz + 7) / 8) * 8) return;
        if(sz == 0) {
            ::operator delete[](arr);
            cp = 0;
            arr = nullptr;
            return;
        };
        Data new_vector{(sz + 7) / 8};
        for(int i = 0; i < (sz + 7) / 8; ++i)
        {
            new_vector[i] = arr[i];
        }
        ::operator delete[](arr);
        arr = new_vector.newarr;
        new_vector.newarr = nullptr;
        cp = ((sz + 7) / 8) * 8;
    }
    void push_back(bool newelem)
    {
        if(cp == sz)
        {
            reserve(cp == 0 ? 8 : cp * 2);
        }
        (*this)[sz] = newelem;
        ++sz;
    }
    void pop_back()
    {
        if(sz > 0)
        {
            --sz;
        }
    }
    void resize(int newsize, bool default_value = false)
    {
        if(newsize < 0) throw std::invalid_argument("длина положительна должна быть");
        else{
            reserve(newsize);
            for(int i = sz; i < newsize; ++i)
            {
                (*this)[i] = default_value;
            }
            sz = newsize;
        }
    }
    void clear()
    {
        sz = 0;
    }
    BitReference& at(int index)
    {
        if(index >= sz){
            throw std::out_of_range("длина вектора меньше индекса");
        }else{
            return (*this)[index];
        }
    }
    const bool& at(int index) const{
        if(index >= sz){
            throw std::out_of_range("длина вектора меньше индекса");
        }else{
            return (*this)[index];
        }
    }
    BitReference* begin()
    {
        return (*this)[0];
    }
    BitReference* end()
    {
        return (*this)[size() - 1];
    }
    int capacity() const {
        return cp;
    }
    int size() const{
        return sz;
    }
    friend std::ostream& operator<<(std::ostream& os, const vector<bool>& el) 
    {
        os << "{";
        for (int i = 0; i < el.size(); ++i)
        {
            os << el[i] << " ";
        }
        os << "}";
        return os;
    }
};