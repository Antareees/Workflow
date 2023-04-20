#include <iostream>
using namespace std;

int main()
{
    int n, X;
    cout << "n = ";
    cin >> n;
    cout << "X = ";
    cin >> X;
    cout << endl;
    //создание
    int *mas = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "mas[" << i << "] = ";
        cin >> mas[i];
    }
    cout << endl;
    //вывод
    for (int i = 0; i < n; i++)
        cout << mas[i] << ' ';
    cout << "\n\n";
    //удаление
    for (int i = 0; i < n; i++)
    {
        if (mas[i] % X == 0)
        {
            for (int j = i + 1; j < n; j++)
            {
                int b = mas[j];
                mas[j - 1] = b;
            }
            i--;
            n--;
        }
    }
    //вывод
    for (int i = 0; i < n; i++)
        cout << mas[i] << ' ';
    cout << endl;

    return 0;
}

