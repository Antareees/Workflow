#include <iostream>1
using namespace std;

template <typename X>
X **create(X c, int n, int m) //создание
{
    X **a = new X *[n];
    for (int i = 0; i < n; i++)
        a[i] = new X[m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    cout << endl;
    return a;
}

template <typename X>
X *create_x_str(X c, int m) //создание
{
    X *a = new X[m];
    for (int i = 0; i < m; i++)
    {
        cout << "a_x[" << i << "] = ";
        cin >> a[i];
    }
    cout << endl;
    return a;
}

template <typename X>
void print(X **a, int n, int m) //вывод
{
    for (int i = 0; i < n; i++, cout << endl)
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
    cout << endl;
}

template <typename X>
void print_x_str(X *a, int m) //вывод
{
    for (int j = 0; j < m; j++)
        cout << a[j] << " ";
    cout << "\n\n";
}

template <typename X>
X **change(X **a, int n, int m, X *a_x_str) //преобразование
{
    for (int j = 0; j < n; j++)
    {
        if (j % 2 != 0)
        {
            for (int i = 0; i < n; i++)
                a[i][j] = a_x_str[i];
        }
    }
    return a;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int n, m;
    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;
    char c;
    do
    {
        cout << "Введите тип:\n1 - int\n2 - double\n3 - char\n4 - float\n";
        int k;
        cin >> k;
        switch (k)
        {
        case 1:
        {
            int c = 1;
            int **a = create(c, n, m);
            int *a_x = create_x_str(c, m);
            cout << "INT:\n";
            print(a, n, m);
            print_x_str(a_x, m);
            a = change(a, n, m, a_x);
            cout << "New:\n";
            print(a, n, m);
            break;
        }
        case 2:
        {
            double c1 = 1;
            double **a1 = create(c1, n, m);
            double *a_x = create_x_str(c1, m);
            cout << "DOUBLE:\n";
            print(a1, n, m);
            print_x_str(a_x, m);
            a1 = change(a1, n, m, a_x);
            cout << "New:\n";
            print(a1, n, m);
            break;
        }
        case 3:
        {
            char c2 = '1';
            char **a2 = create(c2, n, m);
            char *a_x = create_x_str(c2, m);
            cout << "CHAR:\n";
            print(a2, n, m);
            print_x_str(a_x, m);
            a2 = change(a2, n, m, a_x);
            cout << "New:\n";
            print(a2, n, m);
            break;
        }
        case 4:
        {
            float c3 = 1;
            float **a3 = create(c3, n, m);
            float *a_x = create_x_str(c3, m);
            cout << "FLOAT:\n";
            print(a3, n, m);
            print_x_str(a_x, m);
            a3 = change(a3, n, m, a_x);
            cout << "New:\n";
            print(a3, n, m);
            break;
        }
        default:
            cout << "Неправильно введены данные\n";
        }
        cout << "Еще раз? Y - да, N - нет\n";
        cin >> c; // повторяем запуск программы пока не введем N
    } while (c != 'N');
    return 0;
}
