#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n = 12;
    int r, min;
    bool flag = true, flag_2 = true;
    stack<int> stack;
    queue<int> queue, queue_2;
    for (int i = 0; i < n; i++)
    {
        cin >> r;
        queue.push(r);
    }
    min = queue.front();
    for (int i = 0; i < n; i++)
    {
        if (queue.front() < min) 
        {
            min = queue.front();
        }
    
        queue_2.push(queue.front());
        queue.pop();
    }
    while(!queue_2.empty())
    {
        if (queue_2.front() != min || flag == false) 
            queue.push(queue_2.front());
        else 
            flag = false;
        queue_2.pop();
        
    }
    queue_2=queue;
    for (int i = 0; i < queue_2.size(); i++)
    {
        stack.push(queue.front());
        queue.pop();
    }
    while(!stack.empty())
    {
        if (stack.top() != min || flag_2 == false) 
            queue.push(stack.top());
        else 
            flag_2 = false;
        stack.pop();
    }
    while (!queue.empty())
    {
        stack.push(queue.front());
        queue.pop();
    }
    while (!stack.empty())
    {
        queue.push(stack.top());
        stack.pop();
    }
    while(!queue.empty())
    {
        cout << queue.front() << " ";
        queue.pop();    //     8 2 1 6 8 8 1 2 2 8 2 1
    }
}