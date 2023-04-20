#include <iostream>
using namespace std;

int main()
{
    int n, x, y;
    cout << "n = ";
    cin >> n;
    int m = 2 * n;
    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;
    cout << "\n\n";
    //создание
    int *mas = new int[m];
    for (int i = 0; i < n; i++)
    {
        cout << "mas[" << i << "] = ";
        cin >> mas[i];
    }
    cout << "\n\n";
    for (int i = 0; i < n; i++)
        cout << mas[i] << ' ';
    cout << endl;
    for (int i = 0; i < n; i++) //вставка
    {
        if (mas[i] % 10 == x)
        {
            for (int j = n; j > i; j--)
            {
                mas[j] = mas[j - 1];
            }
            mas[i] = y;
            n++;
            i++;
        }
    }
    for (int i = 0; i < n; i++)  //вывод
        cout << mas[i] << ' ';
    cout << endl;
    return 0;
}