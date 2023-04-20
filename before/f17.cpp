#include<iostream>

using namespace std;

void paint(int k, int n)
{
    if (n != k - 1)
    {
        for (int i = 0; i < k; i++) //ввод первой половины до пробела 
            cout << k;
        for (int i = 0; i < 2 * n-2*k; i++) //пробелы в пеовой части 
            cout << '-';
        for (int i = 0; i < k; i++) // ввод первой половины после пробела 
            cout << k;
        cout << endl;
        paint(k + 1, n); 
        for (int i = 0; i < k; i++) //ввод второй половины до пробела 
            cout << k;
        for (int i = 0; i < 2 * n-2*k; i++) //пробелы второй части 
            cout << '-';
        for (int i = 0; i < k; i++) //ввод второй половины после пробела 
            cout << k;
        cout << endl;
    }
}

int main()
{
    int n; cin >> n;
    paint(1,n);
    return 0;
}
