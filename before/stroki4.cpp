// Дан файл, содержащий текст на английском языке, содержащий даты. Вывести в новый файл только те предложения, в которых содержатся корректные даты (в виде «dd.mm.yyyy» или «dd month yyyy»).

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

vector<string> split(string str) //разделение предложения на слова и создание массива
{
    vector<string> prfr;
    string word;
    for (int w = 0; w < str.length(); w++)
    {
        if (str[w] != ' ')
            word += str[w];
        else if (str[w] == ' ' || w == str.length() - 1)
        {
            prfr.push_back(word);
            word.clear();
        }
    }
    return prfr;
}

bool ismonth(string str) // проверка строки на месяц
{
    bool month = false;
    string months[]{
        "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
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

bool vis(int y)
{
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

bool isnumber(string str) // проверка строки на день или год
{
    bool number = true;
    int l = str.length();
    if (l > 4)
        l = 4;
    for (int i = 0; i < l; i++)
    {
        if (!isdigit(str[i]))
        {
            number = false;
            break;
        }
    }
    return number;
}

bool IsYearCorrect(string s)
{
    return (s[0] != '-');
}

bool IsMonthCorrect(string s)
{
    if (isdigit(s[0]))
    {
        if (stoi(s) <= 12) return true;
        else return false;
    }
    else return true;
}

int EndOfMonth(string s1, string s2) {
    int m = stoi(s1);
    int y = stoi(s2);
    switch (m) {
    case 1: case 3: case 5:
    case 7: case 8: case 10: case 12: return 31;
    case 4: case 6: case 9: case 11: return 30;
    case 2: if (vis(y)) return 29;
          else return 28;
    }
    return 0;
}



int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    string text, proffer;
    while (getline(fin, text))
    {
        for (int i = 0; i < text.length(); i++)
        {
            if (((text[i] == '.' || text[i] == '!' || text[i] == '?') && text[i + 1] == ' ') || i == text.length() - 1) // проверка на конец предложения
            {
                proffer += text[i];
                vector<string> v_prfr = split(proffer);
                for (int word = 0; word < v_prfr.size(); word++) // перебор предложения для нахождения дат
                {
                    bool date = isnumber(v_prfr[word]) && ismonth(v_prfr[word + 1]) && isnumber(v_prfr[word + 2]) && IsYearCorrect(v_prfr[word+2]) && IsMonthCorrect(v_prfr[word+1]) && (stoi(v_prfr[word]) <= EndOfMonth(v_prfr[word+1],v_prfr[word+2]));
                    
                    
                    if ((v_prfr[word][2] == '.' && v_prfr[word][5] == '.') && date)
                        fout << proffer << endl;
                }
                proffer.clear();
                i++;
            }
            else
            {
                proffer += text[i]; // запоминание предложения
            }
        }
    }
    fin.close();
    fout.close();
    return 0;
}