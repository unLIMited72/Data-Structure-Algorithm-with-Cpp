#include <iostream>
#include <vector>
#include <stack>

template <typename T>
void reverse(std::vector<T>& vec) {
    std::stack<T, std::vector<T>> stk(vec);

//  std::stack<T> stk;
//  for (const auto& e : vec)
//      stk.push(e);
    
    for (int i = 0; i <vec.size(); i++) {
        vec[i] = stk.top();
        stk.pop();
    }
}

int main()
{
    std::vector<int> vec {10, 20, 30, 40, 50, 60};
    std::vector<std::string> vec2 {"Lim", "Kim", "Park"};
    for (const auto& e : vec) 
        std::cout << e << ", ";
    std::cout << std::endl;
    for (const auto& e : vec2) 
        std::cout << e << ", ";
    std::cout << std::endl;

    reverse<int>(vec);
    reverse<std::string>(vec2);

    for (const auto& e : vec) 
        std::cout << e << ", ";
    std::cout << std::endl;
        for (const auto& e : vec2) 
        std::cout << e << ", ";
    std::cout << std::endl;
}