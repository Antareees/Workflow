#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;


struct t
{
    int h;
    int min;
    int sec;
};

int IsTimeCorrect(int h, int m, int s)
{
    if (h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59) return 0;
    else return 1;
}

string TimeAfterN(int h, int m, int sec, int n)
{
    int newsec = (sec + n) % 60;
    int newmin = m + (sec + n) / 60;
    int newh = (h + newmin / 60) % 24;
    newmin %= 60;
    string ansh = to_string(newh), ansm = to_string(newmin), anss = to_string(newsec);
    if (newh == 0) ansh = "00";
    if (newmin == 0) ansm = "00";
    if (newsec == 0) anss = "00";
    return ansh + ":" + ansm + ":" + anss;
}

int main()
{
    cout << "Enter the time: ";
    string s; 
	cin >> s;
    cout << "Enter N: ";
    int n, f = 1;
	cin >> n;
    if (s.size() != 8)
    {
        cout << "Incorrect time" << endl;
    }
    else
    {
        t time;
        time.h = (int(s[0]) - 48) * 10 + (int(s[1]) - 48);
        time.min = (int(s[3]) - 48) * 10 + (int(s[4]) - 48);
        time.sec = (int(s[6]) - 48) * 10 + (int(s[7]) - 48);
        if (IsTimeCorrect(time.h, time.min, time.sec))
        {
            cout << "Seconds passed " << int (n%60) << endl;
            cout << "Minutes passed " << int (n/60%60) << endl;
            cout << "Hours passed " << int (n/3600) << endl;

            cout << "Time after N seconds " << TimeAfterN(time.h, time.min, time.sec, n) << endl;
        }
        else
        {
            cout << "Incorrect time" << endl;
        }
    }

}


