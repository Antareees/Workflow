#include <iostream>
using namespace std;

int **create(int n) //создание массива
{
    int **a = new int *[n]; //выделение памяти под массив
    int k = -1;
    for (int i = 0; i < n; i++)
        a[i] = new int[n];
    for (int i = 0; i < n; i++){ //заполняем массив
        int m_k=k;
        for (int j = 0; j < n; j++)
        {
            m_k += ((j%2)*(2*n-(1+i*2)))+(1+i*2)*((j+1)%2);
            a[i][j] = m_k;
        }
        k--;
    }    return a;
}

/*int **create(int n, int m) //создание массива
{
    int **a = new int *[n]; //выделение памяти под массив
    int k=0;
    for (int i = 0; i < n; i++)
        a[i] = new int[m];
    for (int i = 0; i < n; i++) //заполняем массив
        for (int j = 0; j < m; j++)
        {
            cout << "a[" << i << "][";
            cout << j << "]=";
            cin >> a[i][j];
        }
    return a;
}
*/

void print(int **a, int n) //вывод массива на экран
{
    for (int i = 0; i < n; i++, cout << endl)
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
    cout << endl;
}

int main()
{
    int n, m; //размерность массива
    cout << "n = ";
    cin >> n;
    int **a = create(n); //создание массива
    print(a, n);         //вывод на экран
    return 0;
}