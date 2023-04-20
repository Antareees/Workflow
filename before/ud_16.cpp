#include <iostream>
using namespace std;

int **create(int n, int m) 
{
    int **mas = new int *[n]; 
    for (int i = 0; i < n; i++)
        mas[i] = new int[m];
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
        {
            cout << "mas[" << i << "][";
            cout << j << "]=";
            cin >> mas[i][j];
        }
    cout << "\n\n";
    return mas;
}

void print(int **mas, int n, int m) 
{
    for (int i = 0; i < n; i++, cout << endl)
        for (int j = 0; j < m; j++)
            cout << mas[i][j] << " ";
    cout << endl;
}

void delete_max(int **mas, int n, int m)
{
    int max = mas[0][0];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mas[i][j] > max)
                max = mas[i][j];
    cout << "max = " << max << "\n\n";
    for (int j = 0; j < m; j++)
    {
        bool flag = false;
        for (int i = 0; i < n; i++)
            if (mas[i][j] == max)
            {
                flag = true;
                break;
            }
        if (flag)
        {
            for (int stolbik = j + 1; stolbik < m; stolbik++)
                for (int stroka = 0; stroka < n; stroka++)
                    mas[stroka][stolbik - 1] = mas[stroka][stolbik];
            m--;
            j--;
        }
    }
    print(mas, n, m);
}

int main()
{
    int n, m; 
    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;
    cout << endl;
    int **mas = create(n, m); 
    print(mas, n, m);         
    delete_max(mas, n, m);
    return 0;
}

/*
4 5 8 2 1
2 4 1 3 9
4 3 7 2 3
9 9 2 7 4
4 6 8 1 3
*/