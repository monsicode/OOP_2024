#include <iostream>

class A{
public:
    int a;
};

class B:public A{
public:
    int b;

};


void f(A& a){ a.a++;}

void g(const A& a){}
void k(A a){}
void l(A* a){}
void m(const A* a){}

int main() {

    B obj;

    f(obj);

    g(obj);
    k(obj);
    l(&obj);
    m(&obj);
}

