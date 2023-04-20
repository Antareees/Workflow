#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int main()
{
    int n;
    cout << "n=";
    cin >> n;
    float y1 = 2, y2 = 1; // начальные значения 
    cout << 1 << "     " << 2 << endl; 
    cout << 2 << "     " << 1 << endl;
    for (int i=3;i<=n;i++)
    {
        float yn=1.0/3.0*((y2/2.0)+(y1/3)); //рассчет функции
        cout << i << "     " << yn << endl; // вывод 
        y1=y2; //переприсваивание
        y2=yn; 
    }
    return 0;
}

