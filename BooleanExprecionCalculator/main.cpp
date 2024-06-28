#include <iostream>
#include <assert.h>
#include "MyString.h"
#include "StringView.h"

class BooleanInterpretator{

   bool data[26]{false};

public:

    void set(char ch, bool val )
    {
        assert(ch >= 'a' && ch <= 'z');
        data[ch - 'a'] = val;
    }

    bool operator()(char ch) const{
        assert(ch >= 'a' && ch <= 'z');
         return  data[ch - 'a'];
    }

    size_t getTrueCount() const{

        size_t count = 0;

        for(int i = 0;  i < 26; i++)
        {
            if(data[i])
                count++;
        }

        return count;
    }

    void excludeValuesByMask(unsigned mask){
        for(int i = 25; i > 0; i--)
        {
            if(data[i])
            {
                if(mask % 2 == 1)
                    data[i] = true;
                else
                    data[i] = false;

                mask/=2;
            }
        }
    }

};


class BooleanExprecion{
public:

    BooleanExprecion() = default;
    BooleanExprecion(const BooleanExprecion& other) = delete;
    BooleanExprecion& operator=(const BooleanExprecion& other) = delete;

    virtual bool eval(const BooleanInterpretator& interpretator) const = 0;

    //тук все едно map-ваме буквите с техните стойности, пълним информация в масива
    virtual void populateVariable(BooleanInterpretator& interpretator) const = 0;

    virtual BooleanExprecion* clone() const = 0;
    virtual ~BooleanExprecion() = default;

};


class Var : public BooleanExprecion{
    char var;
public:

     Var(char ch):var(ch){}

     bool eval(const BooleanInterpretator& interpretator) const override
     {
             return interpretator(var);
     }

     void populateVariable(BooleanInterpretator& interpretator) const override
     {
        interpretator.set(var,true);
     }

     BooleanExprecion* clone() const override {
           return new Var(var);
     }
};


class BinaryOperator : public BooleanExprecion{
protected:
    BooleanExprecion* left;
    BooleanExprecion* right;

public:
    BinaryOperator(BooleanExprecion* left, BooleanExprecion* right) : left(left),right(right){}

    //все някога ще стигне до листо (var)
    void populateVariable(BooleanInterpretator& interpretator) const override
    {
       left->populateVariable(interpretator);
       right->populateVariable(interpretator);
    }

    ~BinaryOperator(){
        delete left;
        delete right;
    }
};


class Conjuction : public BinaryOperator{
public:
    Conjuction(BooleanExprecion* left, BooleanExprecion* right) : BinaryOperator(left,right){}

    bool eval(const BooleanInterpretator& interpretator) const override{
        left->eval(interpretator) && right->eval(interpretator);
    }

    //!!!
    BooleanExprecion* clone() const{
        return new Conjuction(left->clone(),right->clone());
    }
};


class Dejunction : public BinaryOperator{
public:

    Dejunction(BooleanExprecion* left, BooleanExprecion* right): BinaryOperator(left,right){}

    bool eval(const BooleanInterpretator& interpretator) const override{
        return left->eval(interpretator) || right->eval(interpretator);
    }

    BooleanExprecion* clone() const override{
        return new Dejunction(left->clone(),right->clone());
    }

};

class UnaryOperator : public BooleanExprecion{
protected:
    BooleanExprecion* expr;
public:

    UnaryOperator(BooleanExprecion* exp) : expr(exp){}

    void populateVariable(BooleanInterpretator& interpretator) const override {
        expr->populateVariable(interpretator);
    }

    ~UnaryOperator()
    {
     delete expr;
    }
};

class Negate : public UnaryOperator{
public:

    Negate(BooleanExprecion* expr) : UnaryOperator(expr){}

    bool eval(const BooleanInterpretator& interpretator) const override {
           expr->eval(interpretator);
    }

    BooleanExprecion* clone() const override {
        return new Negate(expr->clone());
    }
};

// TODO
BooleanExprecion* factory(StringView str){
      str = str.substr(1, str.length() - 2);

      if (str.length() == 1)
        return new Var(str[0]);
}


class BooleanExpressionHandler{};






int main() {

}
