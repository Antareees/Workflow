#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    setlocale(LC_ALL, "RUS");
    int A, X, Y, p, v, t;
    cin >> A >> X >> Y;
    p = A / 100; //первая цифра
    v = A / 10 % 10; //вторая цифра
    t = A % 10; // третья цифра
    if (((A>999 || A<100) || (Y>9 || Y<0) || (X>4 || X<0))) { //условия на входные данные
        cout << "некорректный ввод";
    }
    else if (p % X == 0 && v % X == 0 && t % X == 0) //кратность цифр на х
    {
        cout << ((p * Y) % 10 * 100 + (v * Y) % 10 * 10 + (t * Y) % 10);
    }
    else if (p % X == 0 && v % X == 0 && t % X != 0)
    {
        cout << ((p * 3) % 10 * 100 + (v * 3) % 10 * 10 + (t * 3) % 10);
    }
    else if (p % X == 0 && v % X != 0 && t % X == 0)
    {
        cout << ((p + Y) % 10 * 100 + (v + Y) % 10 * 10 + (t + Y) % 10);
    }
    else if (p % X != 0 && v % X == 0 && t % X == 0)
    {
        cout << (abs(p - Y) % 10 * 100 + abs(v - Y) % 10 * 10 + abs(t - Y) % 10);
    }
    else
    {
        cout << (p * 2) % 10 * 100 + (v * 2) % 10 * 10 + (t * 2) % 10;
    }
    return 0;
}