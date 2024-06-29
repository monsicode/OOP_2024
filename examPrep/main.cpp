#include <iostream>


enum class color{
    red,
    blue,
    m,
    k,
    n,
};

struct baba{

};


union A{
    int n;
    char ch;
};

struct B{

    B(){}

    B(const B& other){
        std::cout<<"CC of B()";
    }

    B(B&& other)
    {
        std::cout<<"Move of B()";
    }

};

void g(){
    std::cout<<" g() ";
}

static void f(){
    int a = 5;
    g();
   std::cout<<a;
}


int main() {

//  B b;
//  B b2(b);
//  B b3(std::move(b));
//  B b4(b);

  f();

}
