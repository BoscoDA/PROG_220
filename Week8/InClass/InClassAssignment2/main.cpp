#include <string>
#include <iostream>
#include <stack>

bool IsValid(std::string s)
{
    std::stack<char> my_stack;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[')
        {
            my_stack.push(s[i]);
        }
        else if (s[i] == '}' || s[i] == ')' || s[i] == ']')
        {
            if (my_stack.empty())
            {
                return false;
            }
            else if (my_stack.top() != '(' && s[i] == ')')
            {
                return false;
            }
            else if (my_stack.top() != '{' && s[i] == '}')
            {
                return false;
            }
            else if (my_stack.top() != '[' && s[i] == ']')
            {
                return false;
            }
            else
            {
                my_stack.pop();
            }
        }
    }
    if (my_stack.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    std::cout << IsValid("(){}[]") << std::endl; // 1
    std::cout << IsValid("{[]}") << std::endl;   // 1
}