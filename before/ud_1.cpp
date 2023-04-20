#include <iostream>
using namespace std;

int **create(int n, int m)
{
    int **mas = new int *[2 * n];
    for (int i = 0; i < 2 * n; i++)
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
        cout << mas[i] << " ";
    cout << "\n\n";
}

void past(int **mas, int n, int m, int *X)
{
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = 0; j < m; j++)
            if (mas[i][j] < 0)
            {
                flag = false;
                break;
            }
        if (flag)
        {
            for (int stroka = n; stroka > i + 1; stroka--)
                for (int strolbik = 0; strolbik < m; strolbik++)
                    mas[stroka][strolbik] = mas[stroka - 1][strolbik];
            for (int strolbik = 0; strolbik < m; strolbik++)
                mas[i + 1][strolbik] = X[strolbik];
            n++;
            i++;
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
1 1 1 1 1
-2 2 -2 2 2
3 3 -3 3 3
4 4 4 4 4
5 5 5 5 5
*/