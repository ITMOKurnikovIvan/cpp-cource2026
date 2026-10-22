#include <stdexcept>
#include "../include_h/vector.h"

struct vector::Link
{
  double value;
  Link* pred;
  Link* next;
  Link(double value, Link* pred = nullptr, Link* next = nullptr): value(value), pred(pred), next(next) {}
};

vector::vector(): size_(0), elem(nullptr) {}

vector::vector(const vector& other): size_(0), elem(nullptr)
{
  for (int i = 0; i < other.size_; ++i)
  {
    this->append(other.get(i));
  } 
}

vector::vector(vector&& other) noexcept: size_(other.size_), elem(other.elem) 
{
  other.elem = nullptr;
  other.size_ = 0;
}

vector& vector::operator=(const vector& other)
{
  if(this != &other)
  {
    for (int i = 0; i < this->size_; ++i)
    {
      this->erase(0);
    }
    for (int i = 0; i < other.size_; ++i)
    {
      this->append(other.get(i));
    } 

  }
  return *this;
}

vector& vector::operator=(vector&& other) noexcept
{
  if(this != &other)
  {
    for(int i = 0; i < size_; ++i)
    {
      if(elem->pred)
      {
        Link* pred_element = this->elem->pred;
        delete elem;
        this->elem = pred_element; 
      }
      else delete elem;
    }
    this->size_ = other.size_;
    this->elem = other.elem;
    other.elem = nullptr;
    other.size_ = 0;
  }
  return *this;
}

vector::vector(int size_) : size_(size_)
{
  for (int i = 0; i < size_; ++i) {
    Link* new_element = new Link(0.0, elem, nullptr);

    if( elem != nullptr )
    {
      elem->next = new_element;
      elem = new_element;
    }
    else elem = new_element;
  }
}
vector::~vector() 
{
  while( elem != nullptr )
  {
    Link* pred_elem;
    pred_elem = elem->pred;
    delete elem;
    elem = pred_elem;
  }  
  elem = nullptr;
}

int vector::size() const { return size_; }

double vector::get(int n) const 
{
  if( n >= this->size_ || n < 0)
  {
    throw std::out_of_range("длина вектора меньше чем номер элемента");
  }
  Link* end_element = this->elem;
  for (int i = 0; i < this->size_ - n - 1; ++i)
  {
    end_element = end_element->pred;
  }
  return end_element->value;
}

void vector::set(int n, double v) // ВСТАВЛЯЕТ ПЕРЕД ЭТИМ ЭЛЕМЕНТОМ 
{
  Link* new_element = new Link(v, nullptr, nullptr);
  if( n >= this->size_ || n < 0)
  {
    throw std::out_of_range("длина вектора меньше чем номер элемента");
  }
  Link* end_element = this->elem;
  for (int i = 0; i < this->size_ - n - 1; ++i)
  {
    end_element = end_element->pred;
  }
  if(end_element->pred)
  {
    new_element->pred = end_element->pred;
    end_element->pred->next = new_element;
  }
  new_element->next = end_element;
  end_element->pred = new_element;
  size_ += 1;
}

void vector::append(double number)
{
  Link* new_element = new Link(number, elem, nullptr);
  Link* end_element = this->elem;
  if(end_element)
  {
    end_element->next = new_element;
  }
  size_+= 1;
  this->elem = new_element;  
}

int vector::find(double v) const // номер первого вхождения 
{
  int n = -1;
  Link* end_element = elem;
  if (this->elem)
  {
    for( int i = 0; i < size_; ++i)
    {
      if (end_element->value == v)
      {
        n =  size_ - i - 1;
      }
      end_element = end_element->pred;
    }
  }
  return n;
}

void vector::erase(int number)
{
  if( number >= this->size_ || number < 0)
  {
    throw std::out_of_range("длина вектора меньше чем номер элемента");
  }
  Link* end_element = this->elem;
  for (int i = 0; i < this->size_ - number - 1; ++i)
  {
    end_element = end_element->pred;
  }
  if(end_element->pred)
  {
    end_element->pred->next = end_element->next;
  }
  if(end_element->next)
  {
    end_element->next->pred = end_element->pred;
  }
  else
  {
    elem = end_element->pred;
  }
  delete end_element;
  size_ -= 1;
}

void vector::erase(double v)
{
  if(find(v) > -1)
  {
    this->erase(this->find(v));
  }
  else
  {
    throw std::out_of_range("нет такого числа");
  }
}