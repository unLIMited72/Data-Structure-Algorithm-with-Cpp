#include <iostream>

template <typename T>
class DynamicArray
{
private:
    unsigned int sz;
    T* arr;
public:
    explicit DynamicArray(int n) : sz(n) { arr = new T[sz] {}; }
    ~DynamicArray() { delete [] arr; }

    unsigned int size() { return sz; }

    T& operator[] (const int i) { return arr[i]; }
    const T& operator[] (const int i) const { return arr[i]; }
};



int main()
{
    DynamicArray<int> da_int(5);
    DynamicArray<double> da_double(3);

    da_int[0] = 10;
    da_int[1] = 20;
    da_int[2] = 30;

    da_double[0] = 0.1;
    da_double[1] = 0.2;
    da_double[2] = 0.3;

    for (int i = 0; i < da_int.size(); i++) {
        std::cout << da_int[i] << std::endl;
    }

    for (int i = 0; i < da_double.size(); i++) {
        std::cout << da_double[i] << std::endl;
    }
}