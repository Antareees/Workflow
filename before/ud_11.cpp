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

void delete_min(int **mas, int n, int m)
{
    int min = mas[0][0];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mas[i][j] < min)
                min = mas[i][j];
    cout << "min = " << min << "\n\n";
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = 0; j < m; j++)
            if (mas[i][j] == min)
            {
                flag = true;
                break;
            }
        if (flag)
        {
            for (int stroka = i + 1; stroka < n; stroka++)
                for (int stolbik = 0; stolbik < m; stolbik++)
                    mas[stroka - 1][stolbik] = mas[stroka][stolbik];
            n--;
            i--;
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
    delete_min(mas, n, m);
    return 0;
}
/*
4 5 8 2 1
2 4 1 3 2
4 3 7 2 3
9 5 2 7 4
4 6 8 1 3
*/
