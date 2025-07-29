#include <iostream>

int main()
{
    int* ptr = new int[3] {};
    
    ptr[0] = 10;
    ptr[1] = 20;

    for (int i = 0; i < 3; i++) {
        std::cout << ptr[i] << std::endl;
    }

    delete [] ptr;
    ptr = nullptr;
}