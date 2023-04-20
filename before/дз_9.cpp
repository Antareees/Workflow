#include <iostream>
#include <cmath>
using namespace std;
int main() 
{
    setlocale(LC_ALL, "RUS");
    int x;
    cin >> x;
    if ((x * x - 9) == 0) //одз на знаменатель
    {
        cout << "деление на ноль";
    }
    else if ((x < -3) || (x>3 && x<5)) //одз на корень
    {
        cout << "корень из отирцательного числа";
    }
    else if ((x * x + 2 * x + 1) <= 0) //одз на логарифм
    {
        cout << "логарифм из неположительного числа";
    }
    else
    {
        cout << sqrt((x - 5) / (x * x - 9)) + log(x * x + 2 * x + 1); //решение
    }
    return 0;
}

