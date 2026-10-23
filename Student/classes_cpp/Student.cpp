#include "../include_h/Student.h"
#include <vector>
#include <stdexcept>
#include <iostream>

void Student::updateaverage()
{
    if(marks_.empty())
    {
        averageScore_ = 0.0;
        return;
    }
    double sum = 0.0;
    for (std::size_t i = 0; i < marks_.size(); ++i)
    {
        sum += marks_[i];
    }
    averageScore_ = sum / marks_.size();
} 

Student::Student(): name_(""), group_(""), marks_(), averageScore_(0.0){};
Student::Student(const Student& other): name_(other.name_), group_(other.group_), marks_(other.marks_), averageScore_(other.averageScore_) {};
Student::Student(Student&& other) noexcept: name_(std::move(other.name_)), group_(std::move(other.group_)), marks_(std::move(other.marks_)), averageScore_(other.averageScore_)
{
    other.averageScore_ = 0.0;
}
Student::Student(std::string name, std::string group): name_(name), group_(group), marks_(), averageScore_(0.0){}
Student& Student::operator=(const Student& other)
{
    name_ = other.name_ ;
    group_ = other.group_;
    marks_ = other.marks_; 
    averageScore_ = other.averageScore_;
    return *this;
}
Student& Student::operator=(Student&& other) noexcept
{
    name_ = std::move(other.name_);
    group_ = std::move(other.group_);
    marks_ = std::move(other.marks_); 
    averageScore_ = other.averageScore_; 
    other.averageScore_ = 0.0;
    return *this;
}
std::ostream& operator<<(std::ostream& os, const Student& this_)
{
    os << "имя: " << this_.name_ << std::endl;
    os << "группа: " << this_.group_ << std::endl;
    os << "оценки: ";
    for (size_t i = 0; i < this_.marks_.size(); ++i)
    {
        os << this_.marks_[i] << ", ";
    }
    os << std::endl;
    os << "средний балл по 10-бальной: " << (this_.getAverageScore())[0] << std::endl <<
        "средний балл по 5-бальной: "   << (this_.getAverageScore())[1] << std::endl;

    return os;  
}

bool Student::operator<(const Student& other) const 
{
    if ( this != &other) {
        return this -> averageScore_ < other.averageScore_;
    }
    return false;
}

bool Student::operator>=(const Student& other) const 
{
    if (this != &other)
    {
        return !(*this < other);
    }
    return true;
}

bool Student::operator>(const Student& other) const 
{
    if (this != &other)
    {
        return this -> averageScore_ > other.averageScore_;
    }
    return false;
}

bool  Student::operator<=(const Student& other) const 
{
    if (this != &other)
    {
        return !(*this > other);
    }
    return true;
}

bool Student::operator==(const Student& other) const
{
    return (*this >= other && *this <= other);
}

bool Student::operator!=(const Student& other) const
{
    return !(*this == other);
}

void Student::addMark(int mark)
{
    if (mark <= 10 && mark >= 2)
    {
        marks_.push_back(mark);
        updateaverage();
    }
    else throw std::invalid_argument("оценки по 10 бальной системе (1 < оценка < 11)");
}
std::vector<int> Student::getMarks() const
{
    return this -> marks_;
}

std::vector<double> Student::getAverageScore() const 
{
    std::vector<double> averagescore;
    averagescore.push_back(this->averageScore_);
    averagescore.push_back(this->averageScore_ / 2.0);
    return averagescore; 
}

// void Student::printAverageScore() const
// {
//     std::cout << "средний балл по 10-бальной: " << (this->getAverageScore())[0] << std::endl <<
//                  "средний балл по 5-бальной: "   << (this->getAverageScore())[1] << std::endl;
// }
