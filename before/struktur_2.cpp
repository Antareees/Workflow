#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;
struct point
{
    float x;
    float y;
};

float dist(float x1, float y1, float x2, float y2)
{
    return (sqrt(abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2)));
}

int main()
{
    cout << "Enter the number of points: ";
    int n; 
    cin >> n;
    point* a = new point[n];
    float ans = -1, numb;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter coordinates of " << i + 1 << " point x,y: ";
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 0; i < n; i++)
    {
        float sm = 0;
        for (int j = 0; j < n; j++)
        {
            sm += dist(a[i].x, a[i].y, a[j].x, a[j].y);
        }
        if (sm > ans)
        {
            ans = sm;
            numb = i;
        }
    }
    cout << "Answer is point " << numb + 1 << " with sum-dist " << ans << endl;
}           
/* 5
1 3
3 1
1 2
1 2
15 17
*/