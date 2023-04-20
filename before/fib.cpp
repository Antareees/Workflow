#include <iostream>
using namespace std;

int fib(int n)
{
    int f[n];
    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    for (int e: f)
        cout << e << endl;
    return 0;
}

int main()
{
    int n;
    cout << "n=";
    cin >> n;
    fib(n);
    return 0;
}