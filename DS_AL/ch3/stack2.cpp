#include <iostream>
#include <stack>

int main()
{
    std::stack<int> stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.pop();

    std::cout << stk.top() << std::endl;
    stk.push(40);

    while( !stk.empty() ) {
        auto& e = stk.top();
        std::cout << e << ", ";
        stk.pop();
    }
    std::cout << std::endl;
}