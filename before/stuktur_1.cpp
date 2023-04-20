#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Hotel // структура отеля
{
    string f, i, o;
    int day, month, year;
    int days;
};

bool vis(int y)
{ // високосный год
    return ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0);
}

int EndOfMonth(int m, int y)
{ // конец месяца
    switch (m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        if (vis(y))
            return 29;
        else
            return 28;
    default:
        return 0;
    }
}

bool date_correct(int d, int m, int y) //корректность даты
{
    if (d > 0 && d <= EndOfMonth(m, y) && m > 0 && m <= 12 && y > 0)
        return true;
    else
        return false;
}

// счетчик дней
int countday(int day1, int month1, int year1, int day2, int month2, int year2)
{
    int sum1 = 0, sum2 = 0, count = 0;

    // дата 1
    for (int i = 0; i < (year1 - 1); i++)
    {
        if (i % 4 != 0)
        {
            sum1 += 365;
        }
        else
        {
            sum1 += 366;
        }
    }

    for (int j = 0; j < (month1 - 1); j++)
    {
        sum1 += EndOfMonth(j + 1, year1);
    }
    sum1 += day1;
    // дата 2
    for (int i = 0; i < (year2 - 1); i++)
    {
        if (i % 4 != 0)
        {
            sum2 += 365;
        }
        else
        {
            sum2 += 366;
        }
    }

    for (int j = 0; j < (month2 - 1); j++)
    {
        sum2 += EndOfMonth(j + 1, year2);
    }
    sum2 += day2;
    return sum2 - sum1;
}

int main()
{
    int number_guests;
    cout << "Count: ";
    cin >> number_guests;
    vector<Hotel> guest;
    Hotel People;
    for (int i = 0; i < number_guests; i++)
    {
        guest.push_back(People);
        cout << "FIO: ";
        cin >> guest[i].f >> guest[i].i >> guest[i].o; //фио
        bool correct = false;
        do
        {
            cout << "DATE dd mm yyyy: ";
            cin >> guest[i].day >> guest[i].month >> guest[i].year; // дата прибытия
            if (date_correct(guest[i].day, guest[i].month, guest[i].year))
                correct = true;
            else
                cout << "INCORRECT" << endl;
        } while (correct == false);
        cout << "DAYS: ";
        cin >> guest[i].days;
        cout << endl;
    }

    int day, month, year;
    bool correct = false;
    do
    {
        cout << "DATE CHECK dd mm yyyy: ";
        cin >> day >> month >> year;
        if (date_correct(day, month, year)) // дата проверки
            correct = true;
        else
            cout << "INCORRECT" << endl;
    } while (correct == false);

    for (int i = 0; i < number_guests; i++)
    {
        int days_in_hotel = countday(guest[i].day, guest[i].month, guest[i].year, day, month, year); //количество дней до даты меньше чем количество дней в отеле значит человек в отеле
        if (days_in_hotel <= guest[i].days && days_in_hotel >= 0)
            cout << guest[i].f << ' ' << guest[i].i << ' ' << guest[i].o << endl;
    }
    return 0;
}
/* ivanov ivan ivanovich
12.12.2022 
3
petrov petr petrovich
13.12.2022
8
yy zz uu
23.12.2022
1
*/