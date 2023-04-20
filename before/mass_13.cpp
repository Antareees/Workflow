#include <iostream>
using namespace std;

int main()
{

    int k;
    cout << "k = ";
    cin >> k;
    int **a = new int *[k + 1];
    for (int i = 0; i <= k; i++)
        a[i] = new int[i + 1];
    a[0][0] = 1;
    a[1][0] = a[1][1] = 1;
    for (int i = 2; i <= k; i++)
    {
        a[i][0] = 1;
        for (int j = 1; j < i; j++)
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        a[i][i] = 1;
    }
    int S = 0;
    for (int j = 0; j <= k; j++)
        S += a[k][j];
    cout << S;
    cout << endl;
    for (int i = 0; i <= k; i++, cout << endl)
    for (int j = 0; j <=i; j++)
    cout << a[i][j ] << " ";
    return 0;
}