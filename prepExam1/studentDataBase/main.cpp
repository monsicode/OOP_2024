#include <iostream>
#include <fstream>

using namespace std;

struct A {
    A() { cout << "A()"; }
A(const A& other){cout << "A(K)";}
A& operator=(const A& other){cout << "A()op=";}
    ~A() {cout << "~A()";}


};
//
//
//struct B{ B(){cout << "B()";}
//
//    B(const B& other){cout << "B(K)";}
//    B& operator=(const B& other){cout << "B()op=";}
//
//~B() {cout << "~B()";}
//
//};
//
//
//struct C{ C(){cout << "C()";}
//    C(const C& other){cout << "C(K)";}
//    C& operator=(const C& other){cout << "C()op=";}
//    ~C() {cout << "~C()";}
//};
////
//struct X
//{
//    A obj1;
//    B obj2;
//    X()
//    {
//        cout<<"X()";
//    }
//    X(const X& other):obj1(other.obj1),obj2(other.obj2)
//    {cout << "X(K)";}
//    X& operator=(const X& other)
//    {cout << "X()op=";}
//    ~X(){cout<<"~X()";}
//};
//
//
////struct A{
////    int n;
////    int arr[];
////};
////
////struct B{
////    //char arr[];
////    uint32_t n;
////};
//
//union Test {
//    int a;
//    char ch;
//    bool b;
//} test;
//
//
//void g1(A obj) {}
//void g2(const A obj) {}
//void g3(A& obj) {}
//void g4(const A& obj) {}
//void g5(A* ptr) {}
//void g6(A* const ptr) {
//
//}
//void g7(const A* ptr) {
//
//}

//void f(const A& obj){
//    g1(obj);
//    g2(obj);
//    g3(obj);
//    g4(obj);
//    g5(&obj);
//    g6(&obj);
//    g7(&obj);
//}

//void f(X obj) {}
//void g(X* obj) {}
//

//
//struct A {
//    int n;
//    void f() {
//        n++;
//    }
//    void g() {}
//
//    ostream& operator<<(ostream& os)
//    {
//        cout <<"wafdaf";
//        return os;
//    }
//};
//int main() {
//
//    A* ptr1 = new A();
//    A& ref = *ptr1; // A ref
//    A* ptr3 = nullptr;
//    ptr1->f(); //1
//    //ref->f(); //2
//    ref.g(); //3
//    ptr3->f(); //4
//    ptr3->g(); //5
//
//}

A func()
{
    A obj;
    return A(obj);
}

int main()
{
 //A a = func();
//    X arr1[2];
//    X* arr2 = new X[2];
//    return 0;

  // cout<< sizeof(A);
//    test.ch = 'F';
//    test.a =0;
//    std::cout << boolalpha<<test.b;

   // X* arr = new X[2];
//    X obj;
//    X obj2 = obj;
//    obj = obj2;
//    f(obj2);
//    g(&obj2);
    uint32_t a;
    uint32_t& b = a;
    cout<<sizeof(b);
//    int мъж = 100;
//    int жена = мъж;
//    жена -= 50;
//    cout << мъж;
}