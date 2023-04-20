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
    cout << "n = ";
    int n;
    cin >> n;
    cout << "a = [ " << endl;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << " ]" << endl;
    set<int> b;
    for (int i = 0; i < n; i++)
    {
        string s = to_string(a[i]);
        for (int j = 0; j < s.size(); j++)
            b.insert(s[j] - '0');
    } 
    for (int i = 0; i < n; i++)
    {
        string s = to_string(a[i]);
        if (s.size() == 2 || s.size() == 3)
        {
            for (int j = 0; j < s.size(); j++)
            {
                if (b.count(s[j] - '0'))
                    b.erase(s[j] - '0');
            }
        }
    }
    cout << "ANS ";
    for (auto it = b.begin(); it != b.end(); it++)
        cout << *it << ' ';
    cout << endl;
}
