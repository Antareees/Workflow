#include <iostream>
using namespace std;

int **create(int n, int m) //создание массива
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

void change(int **a, int n, int m) //преобразование массива
{
    int min = a[0][0], max = a[0][0];               //нач. знач. для min, max
    int n_min = 0, n_max = 0, m_min = 0, m_max = 0; //номера строк
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - i; j++)
        {
            if (a[i][j] > max)
            {
                max = a[i][j];
                n_max = i;
                m_max = j;
            }
        }
        for (int j = m - i; j < m; j++) {
            if (a[i][j] < min){
                min = a[i][j];
                n_min = i;
                m_min = j;
            }
        }
    }
    swap(a[n_min][m_min], a[n_max][m_max]);
}
int main() {
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