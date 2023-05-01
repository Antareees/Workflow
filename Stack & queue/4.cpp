#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n = 9;
    int r, x;
    bool flag = true;
    stack<int> stack, stack_2;
    for (int i = 0; i < n; i++)
    {
        cin >> r;
        stack.push(r);
    }
    while(!stack.empty())
    {
        if (stack.top() % 2 == 1 && flag == true) 
        {   cin >> x;
            stack_2.push(x);
            flag = false;
        }
        stack_2.push(stack.top());
        stack.pop();
    }
    while(!stack_2.empty())
    {
        
        stack.push(stack_2.top());
        stack_2.pop();
    }
    while(!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();      // 1 2 3 4 5 6 7 8 9
    }
}