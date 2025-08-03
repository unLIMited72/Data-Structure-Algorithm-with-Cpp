#include <iostream>
#include <forward_list>
//forward linked list = signly linked list


int main()
{
    std::forward_list<int> list1 {10, 20, 30, 40};
    list1.push_front(40);
    list1.push_front(30);
    
    for (auto val : list1) {
        std::cout << val << ", ";
    }
    std::cout << std::endl;

    size_t cnt  = std::distance(list1.begin(), list1.end());
    std::cout << cnt << std::endl;

    list1.remove(40);
        for (auto val : list1) {
        std::cout << val << ", ";
    }
    std::cout << std::endl;

    list1.remove_if([](int n){return n > 20;});
    
    for (auto val : list1) {
        std::cout << val << ", ";
    }
    std::cout << std::endl;
}
