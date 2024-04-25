#include "Student.h"

Student:: Student(const char* name, int age, int fn):Person(name,age){
    this->fn = fn;
}

void Student::print() const{
    Person::print();
    std::cout<<" FN:"<<fn;
}