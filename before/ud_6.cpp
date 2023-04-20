#include <iostream>
using namespace std;

int **create(int n, int m) 
{
    int **mas = new int *[n]; 
    for (int i = 0; i < n; i++)
        mas[i] = new int[2 * m];
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

int *create_x(int n) 
{
    int *mas = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "X[" << i << "] = ";
        cin >> mas[i];
    }
    cout << endl;
    return mas;
}

void print_x(int *mas, int n) 
{
    for (int i = 0; i < n; i++)
        cout << mas[i] << endl;
    cout << endl;
}

void past(int **mas, int n, int m, int *X)
{
    for (int j = 0; j < m; j++)
    {
        bool flag = true;
        for (int i = 0; i < n; i++)
            if (mas[i][j] % 2 == 0)
            {
                flag = false;
                break;
            }
        if (flag)
        {
            for (int stolbik = m; stolbik > j; stolbik--)
                for (int stroka = 0; stroka < n; stroka++)
                    mas[stroka][stolbik] = mas[stroka][stolbik - 1];
            for (int stroka = 0; stroka < n; stroka++)
                mas[stroka][j] = X[stroka];
            m++;
            j++;
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
    int *X = create_x(m);
    int **mas = create(n, m); 
    print_x(X, m);
    print(mas, n, m); 
    past(mas, n, m, X);
    return 0;
}

/*
1 3 1 4 1
1 3 2 4 1
1 3 3 4 1
1 3 4 4 5
1 3 5 4 1
*/