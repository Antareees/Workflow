/*#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");

    int s=0;
    const int n=5;
    const int m=5;
    int mas[n][m];
    for (int i = 0; i < n; i++) { // создаю массив 
        for (int j = 0; j < m; j++) { // создаю массив 
            mas[i][j] = i+1;
    }
    }
    for (int i = 0; i < n; i++) { // создаю массив 
        for (int j = 0; j < m; j++) { // создаю массив
            cout << "   " << mas[i][j];
        }
        cout << endl;
    }
    for (int i = 0; i < n / 2.0; i++){
        for (int j = 0; j < m; j++) {
            swap(mas[i][j], mas[n - 1 - i][j]);
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++) { // создаю массив 
        for (int j = 0; j < m; j++) { // создаю массив
            cout << "   " << mas[i][j];
        }
        cout << endl;
    }
    return 0;
}*/

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
            a[i][j] = i + 1;
        }
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
    for (int i = 0; i < n / 2.0; i++)
        for (int j = 0; j < m; j++)
            swap(a[i][j], a[n - 1 - i][j]);
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