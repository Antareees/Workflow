#include <bits/stdc++.h>

using namespace std;
int main()
{
    // freopen("input2.txt", "r", stdin);
    string f;
    set<char> g;
    while (cin >> f)
    {
        for (char c : f)
        {
            if (isalpha(c))
            {
                g.insert(c);
            }
        }
    }
    cout << g.size();
}