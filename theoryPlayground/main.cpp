#include <iostream>
using namespace std;

//struct X{
// static int count;
//
// X(){
//     std::cout<<"X() ";
//   if(count == 2)
//       throw 37;
//
//   count ++;
// }
//
// ~X()
// {
//  std::cout<<"~X()";
// }
//
//};
//
//int X::count = 0;

struct A{
    int a = 9;
    A(){cout<<"A() ";}

    A(const A& other){cout<<"A()KK  ";}
    A(A&& other){cout<<"A()MC  ";}

    A& operator=(A&& other){cout<<"op=A MC";}
    A& operator=(const A& other){cout<<"op=A() KK";}

    ~A(){cout<<"~A()";}

};
struct B{B(){cout<<"B()";} ~B(){cout<<"~B()";}};

struct C{
    int c = 99;
    C(){cout<<"c() ";}

    C(const C& other){cout<<"C()KK  ";}
    C(C&& other){cout<<"C()MC  ";}

    C& operator=(C&& other){cout<<"op=C MC";}
    C& operator=(const C& other){cout<<"op=C() KK";}

    ~C(){cout<<"~C()";}
};

struct D{
    int d = 39;
    D(){cout<<"D() ";}

    D(const D& other){cout<<"D()KK  ";}
    D(D&& other){cout<<"D()MC  ";}
    D& operator=(D&& other){cout<<"op=D MC";}
    D& operator=(const D& other){cout<<"op=D() KK";}

    ~D(){cout<<"~D()";}
};

struct F{
    int b = 9;
    F(){cout<<"F() ";}

    F(const F& other){cout<<"F()KK  ";}
    F(F&& other){cout<<"F()MC  ";}
    F& operator=(F&& other){cout<<"op=F MC";}
    F& operator=(const F& other){cout<<"op=F() KK";}

    ~F(){cout<<"~F()";}
};
//struct X{
//  A obj;
//  B obj2;
//
//  X(){
//      cout<<"X()";
//      throw 3;
//  }
//
//  ~X(){
//      cout<<"~X()";
//  }
//
//};

//
//void f(A& obj)
//{
//    cout<<1;
//}
//
//void f(A&& obj)
//{
//    cout<<2;
//}
//void g(A&& obj)
//{
//    cout<<obj.a;
//   f(obj);
//}

//task 5
//void f(A obj){}
//A obj;
//f(obj);
//
//// RVO
//f(A());

//task 6
//void f(A obj){}
//
//void g(A&& obj){ cout<<obj.a;}
//A obj; // A()
//f(std::move(obj));
//g(std::move(obj));//MC

struct X:A,B,C{
    D obj1;
    F obj2;

    X(){}
    X(const X& other):C(other),A(other){cout<<"X()KK";}
    X(X&& other){cout<<"X()MC";}
    X& operator=(X&& other){cout<<"op=X MC";}
    X& operator=(const X& other){cout<<"op=X() KK";}


//    X():obj2(),C(),A(),B(),obj1(){
//        cout<<"X()";
//    }
//    ~X(){
//        cout<<"~X()";
//    }
};

void f(X obj){}
void  g(X&& obj){}

int main() {
    X obj;
    X obj2;

    f(obj);//A B C D F X KK
    g(std::move(obj));//NOTHING
    obj = obj2;//OP=  X ...  защото принтенето е в началото A B ..
}
