#include <iostream>
using namespace std;

template<typename T>
void print(T* arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template<>
void print<char>(char* arr, size_t size)
{
    for(int i = 0; i < size; i++)
    {
        cout<< arr[i]<<" ---- ";
    }
}

int main() {
    int arr1[] = { 1, 2 };
    print(arr1, 2);
    char arr2[] = { 'a', 'b' };
    print(arr2, 2);

}
