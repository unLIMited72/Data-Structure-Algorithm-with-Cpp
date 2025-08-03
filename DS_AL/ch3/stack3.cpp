#include <iostream>
#include <stack>
#include <string>

std::string reverse(const std::string& str) {
    std::stack<char> stk;
    for (const char& c : str)
        stk.push(c);
      
    std::string res;
    while (!stk.empty()) {
        res += stk.top();
        stk.pop();
    }
    return res;
}


int main()
{
    std::string input;
    std::cout << "input : ";
    std::cin >> input; 

    input = reverse(input);

    std::cout << input << std::endl;
}