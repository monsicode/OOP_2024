#include <iostream>

class Test{
    int a = 10;
public:
    friend void testFunc(const Test&);
};

void testFunc(const Test& obj){
 std::cout<<obj.a;
}

int main() {
  const char* start = {"aea"};
  std::cout<<start[2];

}
