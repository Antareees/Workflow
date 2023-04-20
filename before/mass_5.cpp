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

void proizvod(int *massive, int n) //производная
{
    int *massive_2 = new int[n];
    for (int i = 1; i < n + 1; i++)
    {
        massive_2[i-1] = i * massive[i];
    }
    for (int i = 1; i < n ; i++)
    {
        cout << i * massive_2[i] << " ";
    }
}

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    int *massive = create(n);
    print(massive, n);
    proizvod(massive, n);
    return 0;
}