#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    ifstream in;
    in.open("input.txt");
    int k; 
    cout << "Введите к: ";
    cin >> k;
    string s;
    getline(in,s);
    map<string,int> a;
    string str;
    for(int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            if (isalpha(str[0])) a[str]++;
            str = "";
        }
        else
        {
            str += s[i];
        }
    }
    if (str.size() && isalpha(str[0])) a[str]++;
    set<pair<int,string>> ans;
    for(auto it = a.begin(); it != a.end(); it++)
    {
        ans.insert({it->second, it->first});
    }
    int anssz = ans.size();
    for(int i = 0; i < min(anssz, k); i++)
    {
        cout << (--ans.end())->second <<  ' ';
        ans.erase(--ans.end());
    }
    cout << endl;
}