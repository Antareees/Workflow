#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n = 10;
    int r, max, min;
    queue<int> queue, queue_2;
    for (int i = 0; i < n; i++)
    {
        cin >> r;
        queue.push(r);
    }
    max = queue.front();
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
    while(queue_2.front() != min)
    {
        queue_2.push(queue_2.front());
        queue_2.pop();
        
    }
    while(!queue_2.empty())
    {
        cout << queue_2.front() << " ";
        queue_2.pop();   //   2 5 1 4 5 3 4 5 2 1
    }
}