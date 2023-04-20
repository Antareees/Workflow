#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    cout << endl;
    //создание
    float *mas = new float[n];
    for (int i = 0; i < n; i++)
    {
        float x;
        cout << "mas[" << i << "] = ";
        cin >> x;
        mas[i] = x;
    }
    cout << endl;
    //вывод
    for (int i = 0; i < n; i++)
        cout << mas[i] << ' ';
    cout << "\n\n";
    //минимальное
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
        if (mas[i] < min)
            min = mas[i];
    cout << "min = " << min << "\n\n";
    //удаление
    for (int i = 0; i < n; i++)
    {
        if (mas[i] == min)
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
