#include "Polimorphic_ptr.hpp"

class Base {
public:
    virtual ~Base() = default;

    virtual void speak() const {
        std::cout << "I am Base" << std::endl;
    }

    virtual Base* clone() const {
        return new Base(*this);
    }
};

class Derived : public Base {
public:
    void speak() const override {
        std::cout << "I am Derived" << std::endl;
    }
    Derived* clone() const override {
        return new Derived(*this);
    }
};


int main() {

    Polimorphic_ptr<Base> ptr(new Derived());
    Polimorphic_ptr<Base> newPtr =  ptr.release();

    newPtr->speak();

}
