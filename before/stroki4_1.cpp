#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

vector<string> split(string str) // разделение предложения по пробелам
{
    vector<string> sl;
    string slov;
    for (int q = 0; q < str.length(); q++)
    {
        if (isalnum(str[q]))
            slov += str[q];
        else if (!isalnum(str[q]) || q == str.length() - 1)
        {
            sl.push_back(slov);
            slov.clear();
        }
    }
    return sl;
}

bool ismonth(string str) // корректность месяца
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    bool month = false;
    string months[]{"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
    for (int i = 0; i < 12; i++)
    {
        if (str == months[i])
        {
            month = true;
            break;
        }
    }
    return month;
}

int month_num(string month) // номер месяца
{
    transform(month.begin(), month.end(), month.begin(), ::tolower);
    string months[]{"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
    int nomer_m;
    for (int i = 0; i < 12; i++)
    {
        if (months[i] == month)
        {
            nomer_m = i + 1;
            break;
        }
    }
    return nomer_m;
}
bool date_correct(int d, int m, int y) // корректность даты
{
    switch (m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (d <= 0 || d > 31)
            return false;
        else
            return true;
        break;
    case 4:
    case 6:
    case 9:
    case 11: 
        if (d <= 0 || d > 30)
            return false;
        else
            return true;
        break;
    case 2:
        if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) // високосный год
            if (d <= 0 || d > 29)
                return false;
            else
                return true;
        else // невисокосный
            if (d <= 0 || d > 28)
                return false;
            else
                return true;
        break;
    default:
        return false;
    }
}

bool isnumber(string str) // проверка строки число
{
    bool nomer = true;
    for (int i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
        {
            nomer = false;
            break;
        }
    }
    return nomer;
}


int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    string pr, ver;
    while (getline(fin, pr))
    {
        bool data, data1, data2;
        for (int i = 0; i < pr.length(); i++)
        {
            if (((pr[i] == '.' || pr[i] == '!' || pr[i] == '?') && !isgraph(pr[i + 1])) || i == pr.length() - 1) // если конец предложения
            {
                ver += pr[i];
                vector<string> v_prfr = split(ver);
                data = false;
                for (int slov = 0; slov < v_prfr.size() - 2; slov++) // перебор предложения для нахождения дат
                {
                    data1 = isnumber(v_prfr[slov]) && isnumber(v_prfr[slov + 1]) && isnumber(v_prfr[slov + 2]) &&
                              v_prfr[slov].length() == 2 && v_prfr[slov + 1].length() == 2 && v_prfr[slov + 2].length() == 4; // корректность вида  dd.mm.yyyy
                    if (data1)
                        if (date_correct(stoi(v_prfr[slov]), stoi(v_prfr[slov + 1]), stoi(v_prfr[slov + 2]))) // корректность даты
                            data = true;
                        else
                        {
                            data = false;
                            break;
                        }
                    data2 = isnumber(v_prfr[slov]) && ismonth(v_prfr[slov + 1]) && isnumber(v_prfr[slov + 2]) &&
                              v_prfr[slov].length() == 2 && v_prfr[slov + 2].length() == 4; // вид dd month yyyy
                    if (data2)
                        if (date_correct(stoi(v_prfr[slov]), month_num(v_prfr[slov + 1]), stoi(v_prfr[slov + 2]))) // корректность даты
                            data = true;
                        else
                        {
                            data = false;
                            break;
                        }
                }
                if (data)
                    fout << ver << endl;
                ver.clear();
                i++;
            }
            else
            {
                ver += pr[i]; // запоминание 
            }
        }
    }
    fin.close();
    fout.close();
    return 0;
}