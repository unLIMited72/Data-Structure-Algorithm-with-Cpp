#include <iostream>
#include <list>
// DoublyLinkedList

int main()
{
    std::list<int> list1;
    list1.push_back(10);
    list1.push_back(20);

    std::list<int> list2 {10, 20, 30, 40};
    for (auto a : list2) {
        std::cout << a << ", ";
    }
    std::cout << std::endl;

    list2.splice(list2.end(), list1);
    for (auto a : list2) {
        std::cout << a << ", ";
    }
    std::cout << std::endl;

    list2.sort();
    for (auto a : list2) {
        std::cout << a << ", ";
    }
    std::cout << std::endl;
    
    list2.unique();
    for (auto a : list2) {
        std::cout << a << ", ";
    }
    std::cout << std::endl;
}