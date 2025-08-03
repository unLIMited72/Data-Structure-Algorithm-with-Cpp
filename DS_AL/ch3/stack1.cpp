#include <iostream>
#include <vector>

template <typename T>
class Stack
{
private:
    std::vector<T> v;
public:
    void push(const T& e) { v.push_back(e); }
    void pop() { v.pop_back(); }
    const T& top() const { 
        if(v.empty())
            throw std::out_of_range("Stack is empty");
        return v.back();
     }
    bool empty() const { return v.empty(); }
    int size() const { return v.size(); }
};

int main()
{
    Stack<int> stk;
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