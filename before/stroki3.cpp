#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>


using namespace std;

int f(string s)
{ 
    int k, p;
    int l = s.length();
    sort(s.begin(), s.end());
    k = p = 0;
    for (int i = p; i < l; i++)
    {
        if (s[i] == s[i + 1])
        {
            k++;
        }
        else
            p = k;
    }
    return l - k;
}

int main()
{
    string str, srav, word;
    while (getline(cin, str))
    {
        int maxdl = 0, count = 0;
        for (int i = 0; i <=str.length(); i++)
        {
            if (!isalpha(str[i]))
            {
                count = f(srav);
                if (count > maxdl)
                {
                    word = srav;
                    maxdl = count;
                }
                srav.erase();
            }
            else if (isalpha(str[i]))
                srav += str[i];
        }
        cout << "WORDS:" << endl;
        for (int i = 0; i <= str.length(); i++)
        {
            if (!isalpha(str[i]))
            {
                count = f(srav);
                if (count == maxdl)
                    cout << srav << endl;
                srav.erase();
            }
            else if (isalpha(str[i]))
                srav += str[i];
        }
    }
    return 0;
}
// qwertyuiop aaaa ss ASD ghk sjdh qwertyuiop