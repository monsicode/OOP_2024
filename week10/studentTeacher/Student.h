#pragma once
#include <iostream>
#include "Person.h"

class Student : public Person {
    int fn;
public:
    Student(const char* name, int age, int fn);
     void print() const;
};