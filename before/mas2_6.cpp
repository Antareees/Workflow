#include <iostream>
using namespace std;

int **create(int n, int m) 
{
    int **a = new int *[n]; //выделение памяти под массив
    for (int i = 0; i < n; i++)
        a[i] = new int[m];
    for (int i = 0; i < n; i++) //заполняем массив
        for (int j = 0; j < m; j++)
        {
            cout << "a[" << i << "][";
            cout << j << "]=";
            cin >> a[i][j];
        }
    cout << endl
         << endl;
    return a;
}
void print(int **a, int n, int m) //вывод массива на экран
{
    for (int i = 0; i < n; i++, cout << endl)
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
    cout << endl;
}
void change(int **a, int n, int m) //меняем строки местами
{
    int min = a[0][0], max = a[0][0];
    int n_min = 0, n_max = 0;         //номера строк
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] < min)
            { //первый min
                min = a[i][j];
                n_min = i; //номер строки c min
            }
            if (a[i][j] > max)
            { //последний max
                max = a[i][j];
                n_max = i; //номер строки c max
            }
        }
    for (int j = 0; j < m; j++) //обмен строк
        swap(a[n_min][j], a[n_max][j]);
}
int main()
{
    int n, m; //размерность массива
    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;
    int **a = create(n, m); //создание массива
    print(a, n, m);         //вывод на экран
    change(a, n, m);
    print(a, n, m);
    return 0;
}