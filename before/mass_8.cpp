#include <iostream>
using namespace std;

int *create(int n) //создание массива
{
    int *massive = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        cout << "massive[" << i << "] = ";
        cin >> massive[i];
    }
    cout << endl;
    return massive;
}

void print(int *massive, int n) //вывод массива на экран
{
    for (int i = 0; i < n + 1; i++)
        cout << massive[i] << " ";
    cout << endl;
}

int *proizvod_massive(int *massive, int n) //производная
{
    int *massive2 = new int[n];
    for (int i = 1; i < n + 1; i++)
        massive2[i - 1] = i * massive[i];
    return massive2;
}

void new_mnogochlen(int *massive, int *massive2, int n) //новый многочлен
{
    for (int k = 0; k < n + n; k++)
    {
        float S = 0;
        for (int i = 0; i < n + 1; i++)
            for (int j = 0; j < n; j++)
                if (i + j == k)
                    S += massive[i] * massive2[j];
        cout << S << " ";
    }
}

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    int *massive = create(n);
    print(massive, n);
    int *massive2 = proizvod_massive(massive, n);
    print(massive2, n - 1);
    new_mnogochlen(massive, massive2, n);
    return 0;
}