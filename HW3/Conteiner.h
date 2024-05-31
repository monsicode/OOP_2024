#pragma once
#include "PartialFunction.h"
#include "polymorphic_ptr.hpp"
#include "Vector.hpp"

class CollectionFunctions : public PartialFunction {
public:
    CollectionFunctions();
    CollectionFunctions(const CollectionFunctions& other);
    CollectionFunctions(CollectionFunctions&& other) noexcept;
    CollectionFunctions& operator=(const CollectionFunctions&);
    CollectionFunctions& operator=(CollectionFunctions&&) noexcept;
    ~CollectionFunctions() noexcept;

    void addFunction(const polymorphic_ptr<PartialFunction>& func);

    const PartialFunction* operator[](unsigned index) const;
    unsigned getSize() const;

    bool isDefined(uint32_t number) const override;
    uint32_t calculate(uint32_t number) const override;
     uint32_t operator()(uint32_t number) const override{return 0;}
     PartialFunction *clone() const {return new CollectionFunctions(*this);}

protected:
    void free();
    void copyFrom(const CollectionFunctions& other);
    void moveFrom(CollectionFunctions&& other);

     Vector<polymorphic_ptr<PartialFunction>> functions;
    size_t capacity = 0;
    size_t size = 0;
};
























//class CollectionFunctions : public PartialFunction{
//public:
//    CollectionFunctions();
//
//    CollectionFunctions(const CollectionFunctions& other);
//    CollectionFunctions(CollectionFunctions&& other) noexcept;
//
//    CollectionFunctions& operator=(const CollectionFunctions&);
//    CollectionFunctions& operator=(CollectionFunctions&&) noexcept;
//
//    ~CollectionFunctions() noexcept;
//
//    void addFunction(PartialFunction*);
//    void addFunction(const PartialFunction&);
//
//    const PartialFunction* operator[](unsigned) const;
//    unsigned getSize() const;
//
//
//protected:
//    void resize(size_t newCap);
//    void moveFrom(CollectionFunctions&& other);
//    void copyFrom(const CollectionFunctions& other);
//    void free();
//
//    PartialFunction** data = nullptr;
//    size_t capacity = 0;
//    size_t size = 0;
//
//public:
//    bool isDefined(uint32_t number) const override;
//
//

  //  uint32_t calculate(uint32_t number) const override;
//
//    uint32_t operator()(uint32_t number) const override;
//    PartialFunction* clone() const override;
//};


