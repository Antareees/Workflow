#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    int m, n;
    string mes[]{"января", "февраля", "марта", "апреля", "мая", "июня", "июля", "августа","сентября", "октября", "ноября", "декабря"}; // задаю массив с месяцами
    cout << "Введите m и n\n";
    cin >> m >> n;

    switch (m % 12) // если остаток от деления кол-ва месяцев на 12 - 0,2,4,6,7,9,11, то в месяце 31 день, иначе 30, кроме случая когда остаток 1
    {
    case 0:
    case 2:
    case 4:
    case 6:
    case 7:
    case 9:
    case 11: // 31 день
        if (n <= 0 || n > 20) // условие на кол-во дней
            cout << "Неправильно введен день\n";
        else
            cout << 31 - n - 1 << " " << n+1 << " " << mes[m%12] << " " << 2000+m/12;
        break;
    case 3:
    case 5:
    case 8:
    case 10: // 30 дней
        if (n <= 0 || n > 20)
            cout << "Неправильно введен день\n";
        else
            cout << 30 - n - 1 << " " << n+1 << " " << mes[m%12] << " " << 2000+m/12;
        break;
    case 1:
        if ((2000 + (m / 12)) % 400 == 0 || ((2000 + (m / 12)) % 4 == 0 || (2000 + (m / 12)) % 100 != 0)) 
            if (n <= 0 || n > 20)
                cout << "Неправильно введен день\n";
            else
                cout << 29 - n - 1 << " " << n+1 << " " << mes[m%12] << " " << 2000+m/12;

        else 
            if (n <= 0 || n > 20)
                cout << "Неправильно введен день\n";
            else 
                cout << 28 - n - 1 << " "  << n+1 << " " << mes[m%12] << " " << 2000+m/12;
        break;

    default:
        cout << "неправильный месяц";
    }
    return 0;

}