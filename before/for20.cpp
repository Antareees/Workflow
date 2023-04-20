#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int main()
{
    setlocale(LC_ALL, "RUS");
    int k = 2, e = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << k - j * 2 << " ";
        }
        cout << endl;
        k = k + 2;
        for (int j = 0; j < i + 1; j++)
        {
            cout << e << " ";
        }
        cout << endl;
        e = e + 3;
    }
    return 0;
}