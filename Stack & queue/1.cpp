#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n = 10;
    int r, max, min;
    stack<int> stack, stack_2;
    for (int i = 0; i < n; i++)
    {
        cin >> r;
        stack.push(r);
    }
    max = stack.top();
    min = stack.top();
    for (int i = 0; i < n; i++)
    {
        if (stack.top() < min) 
        {
            min = stack.top();
        }
        if (stack.top() > max) 
        {
            max = stack.top();
        }
        stack_2.push(stack.top());
        stack.pop();
    }
    while(!stack_2.empty())
    {
        if (stack_2.top() == min)
        {
            stack.push(max);
        }
        stack.push(stack_2.top());
        stack_2.pop();
    }
    while(!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();                 // 2 8 4 1 2 8 8 1 2 8
    }
}