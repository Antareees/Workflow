#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    int n;
    float x, eps = 0.00001;
    cin >> n >> x;
    float a = x, S = a;
    cout << left << setw(3) << "i" // вывод заголовка таблтцы
         << "\t| " << setw(10) << "a"
         << "\t| " << setw(10) << "S" << endl;
    cout << left << setw(3) << "1" // вывод первой строки
         << "\t| " << setw(10) << a
         << "\t| " << setw(10) << S << endl;
    for (int i = 2; i <= n; i++)
    {   
        a *= x*x / ( 2*i * (2*i + 1)); //увеличение предыдущего 
        S += a;
        cout << left << setw(3) << i << "\t| " << setw(10) << a << "\t| " << setw(10) << S << endl; 
    }
    return 0;
}