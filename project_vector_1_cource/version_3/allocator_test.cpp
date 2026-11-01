template<typename T>
struct NewDeleteAllocator {
    using value_type = T;

    NewDeleteAllocator() noexcept = default;

    template<typename U>
    NewDeleteAllocator(const NewDeleteAllocator<U>&) noexcept {}

    T* allocate(std::size_t n) {
        return static_cast<T*>(::operator new(n * sizeof(T))); // ::operator new(int n) выделяет сырую память не вызывая конструкторов 
                                                                // new (указатель) T(arg ) вызывает конструктор и не выделяет память 
    }

    void deallocate(T* p, std::size_t) noexcept {
        ::operator delete(p);
    }

    template<typename U>
    bool operator==(const NewDeleteAllocator<U>&) const noexcept { return true; }
    template<typename U>
    bool operator!=(const NewDeleteAllocator<U>&) const noexcept { return false; }

    // нужны операторы сравнения , чтобы понимать что один и тот же аллокатор используется для std::alocator_traite
};