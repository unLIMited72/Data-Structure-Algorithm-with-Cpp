/*
    [] : brackets
    {} : braces
    () : parentheses
    condition :
    1. The number of () opened and closed must be the same for each type of ().
    2. In () of the same kind, the () that open must appear before the () that close.
    3. The closing () paired with the () in the last opening must appear first.
*/

#include <iostream>
#include <stack>
#include <string>

bool check_brackets(const std::string& str) {
    std::stack<char> stk;
    for (const char& c : str) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if ( stk.empty() ||
                (c == ')' && stk.top() != '(') ||
                (c == ']' && stk.top() != '[') ||
                (c == '}' && stk.top() != '{')) 
            { return false; } else {
                stk.pop();
            }
        }
    }
    return stk.empty();
}

int main()
{
    std::string str = "{3 + 2(2*3*[2-3])}";

    std::cout << check_brackets(str) << std::endl;

    std::string str2 = " (42+{34-2*(23 + 22} - 2)";

    std::cout << check_brackets(str2) << std::endl;
}