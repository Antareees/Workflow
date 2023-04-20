#include <iostream>
using namespace std;

int main()
{
    int n, x;
    cout << "n = ";
    cin >> n;
    int m = 2 * n;
    cout << "x = ";
    cin >> x;
    cout << "\n\n";
    //создание
    int *mas = new int[m];
    for (int i = 0; i < n; i++)
    {
        cout << "mas[" << i << "] = ";
        cin >> mas[i];
    }
    cout << "\n\n";
    //вывод
    for (int i = 0; i < n; i++)
        cout << mas[i] << ' ';
    cout << "\n\n";
    //вставка
    for (int i = 0; i < n; i++)
    {
        if (mas[i] == x)
        {
            for (int j = n; j > i + 1; j--)
            {
                mas[j] = mas[j - 1];
            }
            mas[i + 1] = x;
            n++;
            i++;
        }
    }
    //вывод
    for (int i = 0; i < n; i++)
        cout << mas[i] << ' ';
    cout << endl;
    return 0;
}
