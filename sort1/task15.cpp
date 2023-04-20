#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

struct date
{ // дата
    int dd, mm, yy;
};

struct people
{                     // данные о человеке
    string Surname;   // фамилия
    string Position;  // должность
    date DateOfBirth; // дата рождения
    int XP;           // стаж работы
    int Salary;       // зарплата
};

date Str_to_Date(string str)
{ // из строки в дату
    date x;
    string temp = str.substr(0, 2); // день
    x.dd = atoi(temp.c_str());
    temp = str.substr(3, 2); // месяц
    x.mm = atoi(temp.c_str());
    temp = str.substr(6, 4); // год
    x.yy = atoi(temp.c_str());
    return x;
}

vector<people> inFile()
{ // ввод из файла
    vector<people> x;
    people temp;
    while (in.peek() != EOF)
    {
        in >> temp.Surname;  // фамилия
        in >> temp.Position; // позиция
        string tmp;          // дата рождения
        in >> tmp;
        temp.DateOfBirth = Str_to_Date(tmp);
        in >> temp.XP;     // стаж работы
        in >> temp.Salary; // зарплата
        x.push_back(temp);
    }
    return x;
}

void print(people x)
{                                          // вывод в файл
    out << setw(10) << left << x.Surname;  // по левому краю, 10 позиций для фамилии
    out << left << setw(10) << x.Position; // 20 позиций для должности
    if (x.DateOfBirth.dd < 10)
        out << left << '0' << x.DateOfBirth.dd << '.'; // добавляем 0
    else
        out << left << x.DateOfBirth.dd << '.';
    if (x.DateOfBirth.mm < 10)
        out << '0' << x.DateOfBirth.mm << '.';
    else
        out << x.DateOfBirth.mm << '.';
    out << left << setw(6) << x.DateOfBirth.yy;  // на год 6 позиций
    out << left << setw(4) << x.XP;              // стаж
    out << left << setw(10) << x.Salary << endl; // запрлата
}


bool operator>(date a, date b) // сравнение даты (тем больше, чем раньше дата)
{
    if (a.yy < b.yy)
        return true;
    else if (a.yy == b.yy) {
        if (a.mm < b.mm)
            return true;
        else if (a.mm == b.mm) {
            if (a.dd < b.dd)
                return true;
        }
    }
    return false;
}

bool operator>(people a, people b)
{ // переопределяем оператор <
    if (a.Surname > b.Surname)
        return true;
    else if (a.Surname == b.Surname) {
        if (a.XP > b.XP)
            return true;

        else if (a.XP == b.XP) {
            if (a.DateOfBirth > b.DateOfBirth) // тем больше, чем раньше дата
                return true;
        }
    }
    return false;
}

void insertionSort(vector<people> &x, int n) // сортировка вставками
{
    int i, j;
    people key;
    for (i = 1; i < n; i++) {
        key = x[i];
        j = i - 1;

        while (j >= 0 && x[j] > key) {
            x[j + 1] = x[j];
            j = j - 1;
        }
        x[j + 1] = key;
    }
}

int main()
{
    vector<people> x;
    x = inFile();
    insertionSort(x, x.size());

    for (int i = 0; i < x.size(); i++)
        print(x[i]);
    return 0;
}
