#include <iostream>
#include "Optional.hpp"

int main() {
    try {
        Optional<int> a;
        a.setValue(5);

        a.setValue(7);
        std::cout<<a.getValue();
    }
    //защо пишем в exception-ите като в крайна сметка не ни се изписва съобщението което е там
    catch(std::logic_error)
    {
        std::cout<<"No value";
    }

}
